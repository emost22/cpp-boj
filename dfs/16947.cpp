#include <iostream>
#include <queue>
#include <cstring>
#define MAX 3001
using namespace std;

vector<int> graph[MAX];
bool visit[MAX], cycle[MAX];
int N;

int bfs(int s) {
	queue<int> q;
	q.push(s);
	visit[s] = true;
	for (int t = 0; !q.empty(); t++) {
		int qsize = q.size();
		while (qsize--) {
			int x = q.front();
			q.pop();

			if (cycle[x]) return t;

			for (int i = 0; i < graph[x].size(); i++) {
				int next = graph[x][i];

				if (visit[next]) continue;
				q.push(next);
				visit[next] = true;
			}
		}
	}

	return 0;
}

bool dfs(int s, int v, int cnt) {
	visit[v] = true;

	for (int i = 0; i < graph[v].size(); i++) {
		int next = graph[v][i];

		if (s == next && cnt >= 2) {
			cycle[v] = true;
			return true;
		}

		if (visit[next]) continue;
		if (dfs(s, next, cnt + 1)) {
			cycle[v] = true;
			return true;
		}
	}

	return false;
}

void func() {
	for (int i = 1; i <= N; i++) {
		if (cycle[i]) continue;
		dfs(i, i, 0);
		memset(visit, false, sizeof(visit));
	}

	for (int i = 1; i <= N; i++) {
		cout << bfs(i) << ' ';
		memset(visit, false, sizeof(visit));
	}
	cout << '\n';
}

void input() {
	int u, v;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
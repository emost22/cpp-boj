#include <iostream>
#include <vector>
#include <queue>
#define MAX 300001
using namespace std;

vector<int> graph[MAX];
bool visit[MAX];
int N, M, S, E;

int bfs() {
	queue<int> q;
	q.push(S);
	visit[S] = true;
	for (int t = 0; !q.empty(); t++) {
		int qsize = q.size();
		while (qsize--) {
			int x = q.front();
			q.pop();

			if (x == E) return t;

			if (x - 1 > 0 && !visit[x - 1]) {
				q.push(x - 1);
				visit[x - 1] = true;
			}

			if (x + 1 <= N && !visit[x + 1]) {
				q.push(x + 1);
				visit[x + 1] = true;
			}

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

void func() {
	cout << bfs() << '\n';
}

void input() {
	int u, v;
	cin >> N >> M >> S >> E;
	while (M--) {
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
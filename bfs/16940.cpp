#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 100001
using namespace std;

vector<int> graph[MAX];
int ordered[MAX];
bool visit[MAX];
int N;

bool cmp(int a, int b) {
	return ordered[a] < ordered[b];
}

int bfs(int s) {
	queue<int> q;
	q.push(s);
	visit[s] = true;

	int now = 1;
	for (int t = 1; !q.empty(); t++) {
		int qsize = q.size();
		while (qsize--) {
			int x = q.front();
			q.pop();

			if (ordered[x] != now) {
				return 0;
			}
			now++;

			for (auto y : graph[x]) {
				if (visit[y]) continue;

				q.push(y);
				visit[y] = true;
			}
		}
	}

	return 1;
}

void func() {
	for (int i = 1; i <= N; i++) {
		sort(graph[i].begin(), graph[i].end(), cmp);
	}

	cout << bfs(1) << '\n';
}

void input() {
	int u, v;
	cin >> N;
	for (int i = 1; i < N; i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	int x;
	for (int i = 1; i <= N; i++) {
		cin >> x;
		ordered[x] = i;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
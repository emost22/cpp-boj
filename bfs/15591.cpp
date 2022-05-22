#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 5001
using namespace std;
typedef pair<int, int> pi;

vector<pi> graph[MAX];
bool visit[MAX];
int N, M;

void bfs(int sx, int k) {
	queue<pi> q;
	q.push({ sx, 1e9 });
	memset(visit, false, sizeof(visit));
	visit[sx] = true;

	int cnt = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int w = q.front().second;
		q.pop();

		for (int i = 0; i < graph[x].size(); i++) {
			int next = graph[x][i].first;
			int nextw = min(w, graph[x][i].second);

			if (visit[next]) continue;
			if (nextw < k) continue;

			q.push({ next, nextw });
			visit[next] = true;
			cnt++;
		}
	}

	cout << cnt << '\n';
}

void func() {
	int k, v;
	while (M--) {
		cin >> k >> v;
		bfs(v, k);
	}
}

void input() {
	int u, v, w;
	cin >> N >> M;
	for (int i = 0; i < N - 1; i++) {
		cin >> u >> v >> w;
		graph[u].push_back({ v,w });
		graph[v].push_back({ u,w });
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
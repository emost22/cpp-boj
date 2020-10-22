#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

vector<int> graph[51], ans[51];
bool visit[51];
int N, score[51];

void bfs(int v) {
	queue<pair<int, int> > q;
	q.push({ v, 0 });
	visit[v] = true;
	int s = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int cnt = q.front().second;
		q.pop();

		s = max(s, cnt);

		for (int i = 0; i < graph[x].size(); i++) {
			int next = graph[x][i];

			if (visit[next]) continue;

			q.push({ next, cnt + 1 });
			visit[next] = true;
		}
	}

	score[v] = s;
	ans[s].push_back(v);
	return;
}

void func() {
	int sc = 51;
	for (int i = 1; i <= N; i++) {
		memset(visit, false, sizeof(visit));
		bfs(i);
		sc = min(sc, score[i]);
	}

	cout << sc << ' ' << ans[sc].size() << '\n';
	for (int i = 0; i < ans[sc].size(); i++) {
		cout << ans[sc][i] << ' ';
	}
	cout << '\n';
}

void input() {
	int u, v;
	cin >> N;
	while (1) {
		cin >> u >> v;
		if (u == -1) break;

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
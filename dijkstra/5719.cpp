#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define INF 1000000000
using namespace std;

vector<pair<int, int> > graph[500], rgraph[500];
bool visit[500], chk[500][500];
int d[500], N, M, S, D, ans;

void dijkstra(int s) {
	for (int i = 0; i < N; i++) d[i] = INF;
	d[s] = 0;
	ans = INF;
	priority_queue<pair<int, int> > q;
	q.push({ 0, s });
	while (!q.empty()) {
		int now = q.top().second;
		int dis = -q.top().first;
		q.pop();

		if (now == D) ans = min(ans, dis);
		if (d[now] < dis) continue;

		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i].first;
			int nextdis = graph[now][i].second + dis;

			if (chk[now][next]) continue;
			if (d[next] > nextdis) {
				d[next] = nextdis;
				q.push({ -nextdis, next });
			}
		}
	}
}

void dfs(int v) {
	visit[v] = true;
	for (int i = 0; i < rgraph[v].size(); i++) {
		int next = rgraph[v][i].first;
		int dis = rgraph[v][i].second;

		if (dis + d[next] == d[v]) {
			chk[next][v] = true;
			if (visit[next]) continue;
			dfs(next);
		}
	}
}

void CLEAR() {
	for (int i = 0; i < N; i++) {
		graph[i].clear();
		rgraph[i].clear();
	}

	memset(chk, false, sizeof(chk));
	memset(visit, false, sizeof(visit));
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int u, v, w;
	while (1) {
		cin >> N >> M;
		if (!N) return 0;
		cin >> S >> D;

		while (M--) {
			cin >> u >> v >> w;
			graph[u].push_back({ v,w });
			rgraph[v].push_back({ u,w });
		}
		dijkstra(S);
		dfs(D);
		dijkstra(S);

		if (ans == INF) ans = -1;
		cout << ans << '\n';
		
		CLEAR();
	}
}
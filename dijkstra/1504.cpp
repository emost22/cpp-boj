#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
#define INF 1000000000
using namespace std;

vector<pair<int, int> > graph[801];
int num[3];
int d[3][801];
int N, E, u, v, w, s, e, ans;

int Min(int x, int y) {
	return x < y ? x : y;
}

void dijkstra(int v, int index) {
	d[index][v] = 0;
	priority_queue<pair<int, int> > q;
	q.push(make_pair(0, v));

	while (!q.empty()) {
		int now = q.top().second;
		int dis = -q.top().first;
		q.pop();

		if (d[index][now] < dis) continue;

		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i].first;
			int nextdis = dis + graph[now][i].second;

			if (d[index][next] > nextdis) {
				d[index][next] = nextdis;
				q.push(make_pair(-nextdis, next));
			}
		}
	}
}

int main() {
	scanf("%d %d", &N, &E);
	while (E--) {
		scanf("%d %d %d", &u, &v, &w);
		graph[u].push_back(make_pair(v, w));
		graph[v].push_back(make_pair(u, w));
	}
	
	for (int i = 0; i < 3; i++) {
		for (int j = 1; j <= N; j++) {
			d[i][j] = INF;
		}
	}
	
	num[0] = 1;
	scanf("%d %d", &num[1], &num[2]);
	for (int i = 0; i < 3; i++) {
		dijkstra(num[i], i);
	}

	ans = Min(d[0][num[1]] + d[1][num[2]] + d[2][N], d[0][num[2]] + d[2][num[1]] + d[1][N]);
	if (ans >= INF || ans < 0) printf("-1\n");
	else printf("%d\n", ans);

	return 0;
}
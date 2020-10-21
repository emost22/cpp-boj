#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
using namespace std;

vector<pair<int, int> > graph[20001];
int d[20001];
int V, E, K, INF = 1000000000;

void dijkstra(int v) {
	d[v] = 0;
	priority_queue<pair<int, int> > q;

	q.push(make_pair(0, v));
	while (!q.empty()) {
		int dis = -q.top().first;
		int now = q.top().second;
		q.pop();

		if (d[now] < dis) continue;

		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i].first;
			int nextdis = dis + graph[now][i].second;

			if (d[next] > nextdis) {
				d[next] = nextdis;
				q.push(make_pair(-nextdis, next));
			}
		}
	}
}

int main() {
	int u, v, w;
	scanf("%d %d %d", &V, &E, &K);
	
	while (E--) {
		scanf("%d %d %d", &u, &v, &w);
		graph[u].push_back(make_pair(v, w));
	}

	for (int i = 1; i <= V; i++) {
		d[i] = INF;
	}
	dijkstra(K);

	for (int i = 1; i <= V; i++) {
		if (d[i] == INF) printf("INF\n");
		else printf("%d\n", d[i]);
	}

	return 0;
}
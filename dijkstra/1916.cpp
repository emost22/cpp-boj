#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
#define INF 1000000000
using namespace std;

vector<pair<int, int> > graph[1001];
int d[1001];
int N, M, u, v, w;

void dijkstra(int v) {
	d[v] = 0;
	priority_queue<pair<int, int> > q;
	q.push(make_pair(0, v));
	while (!q.empty()) {
		int now = q.top().second;
		int dis = -q.top().first;
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
	int s, e;

	scanf("%d %d", &N, &M);
	while (M--) {
		scanf("%d %d %d", &u, &v, &w);

		graph[u].push_back(make_pair(v, w));
	}

	for (int i = 1; i <= N; i++) {
		d[i] = INF;
	}

	scanf("%d %d", &s, &e);
	dijkstra(s);
	printf("%d\n", d[e]);

	return 0;
}
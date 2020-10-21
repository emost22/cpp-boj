#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
#define INF 1000000000
using namespace std;

vector<pair<int, int> > graph[1001];
vector<int> path[1001];
int d[1001];
int N, M, u, v, w, ans;

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

			if (d[next] >= nextdis) {
				if (d[next] > nextdis) {
					ans -= path[next].size();
					path[next].clear();
				}
				else if (d[next] == nextdis) {
					ans -= path[next].size();
					path[next].clear();
				}
				path[next].push_back(now);
				ans++;
				d[next] = nextdis;
				q.push(make_pair(-nextdis, next));
				
			}
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	while (M--) {
		scanf("%d %d %d", &u ,&v, &w);
		graph[u].push_back(make_pair(v, w));
		graph[v].push_back(make_pair(u, w));
	}

	for (int i = 1; i <= N; i++) d[i] = INF;
	dijkstra(1);
	printf("%d\n", ans);
	for (int i = 1; i <= N && ans; i++) {
		if (path[i].size()) {
			printf("%d %d\n", i, path[i][0]);
			ans--;
		}
	}

	return 0;
}
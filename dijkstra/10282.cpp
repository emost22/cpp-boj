#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
#define INF 1000000000
using namespace std;

vector<pair<int, int> > graph[10001];
int d[10001];
int N, D, C, a, b, s, T, ans;

int Max(int x, int y) {
	return x > y ? x : y;
}

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
	int Testcase;

	scanf("%d", &Testcase);
	while (Testcase--) {
		scanf("%d %d %d", &N, &D, &C);
		while (D--) {
			scanf("%d %d %d", &b, &a, &s);
			graph[a].push_back(make_pair(b, s));
		}

		for (int i = 1; i <= N; i++) {
			d[i] = INF;
		}

		dijkstra(C);
		for (int i = 1; i <= N; i++) {
			if (d[i] != INF) {
				T = Max(T, d[i]);
				ans++;
			}
			graph[i].clear();
			d[i] = INF;
		}

		printf("%d %d\n", ans, T);
		ans = 0;
		T = 0;
	}

	return 0;
}
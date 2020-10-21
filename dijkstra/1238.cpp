#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
#define INF 1000000000
using namespace std;

vector<pair<int, int> > graph[1001];
int d_in[1001], d_out[1001];
int N, M, X, max_dis;

int Max(int x, int y) {
	return x > y ? x : y;
}

void dijkstra_in(int v) {
	priority_queue<pair<int, int> > q;
	q.push(make_pair(0, v));
	while (!q.empty()) {
		int now = q.top().second;
		int dis = -q.top().first;
		q.pop();

		if (d_in[now] < dis) continue;
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i].first;
			int nextdis = dis + graph[now][i].second;

			if (d_in[next] > nextdis) {
				d_in[next] = nextdis;
				q.push(make_pair(-nextdis, next));
			}
		}
	}
}

void dijkstra_out(int v) {
	priority_queue<pair<int, int> > q;
	q.push(make_pair(0, v));
	while (!q.empty()) {
		int now = q.top().second;
		int dis = -q.top().first;
		q.pop();

		if (d_out[now] < dis) continue;
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i].first;
			int nextdis = dis + graph[now][i].second;

			if (d_out[next] > nextdis) {
				d_out[next] = nextdis;
				q.push(make_pair(-nextdis, next));
			}
		}
	}
}

int main() {
	int s, e, T;
	scanf("%d %d %d", &N, &M, &X);
	while (M--) {
		scanf("%d %d %d", &s, &e, &T);

		graph[s].push_back(make_pair(e, T));
	}

	for (int i = 1; i <= N; i++) {
		d_out[i] = INF;
	}

	d_out[X] = 0;
	dijkstra_out(X);
	for (int i = 1; i <= N; i++) {
		if (i == X) continue;
		for (int j = 1; j <= N; j++) {
			d_in[j] = INF;
		}
		d_in[i] = 0;
		dijkstra_in(i);
		max_dis = Max(max_dis, d_in[X] + d_out[i]);
	}

	printf("%d\n", max_dis);

	return 0;
}
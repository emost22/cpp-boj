#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
#define INF 1000000000
using namespace std;

vector<pair<int, int> > graph[20001];
int d[20001];
int N, M, A, B, num, ans, cnt;

int Min(int x, int y) {
	return x < y ? x : y;
}

void dijkstra(int v) {
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

				if (ans < nextdis) {
					num = next;
					ans = nextdis;
					cnt = 1;
				}
				else if (ans == nextdis) {
					num = Min(num, next);
					cnt++;
				}
			}
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	while (M--) {
		scanf("%d %d", &A, &B);
		graph[A].push_back(make_pair(B, 1));
		graph[B].push_back(make_pair(A, 1));
	}

	for (int i = 2; i <= N; i++) d[i] = INF;

	dijkstra(1);
	printf("%d %d %d\n", num, ans, cnt);

	return 0;
}
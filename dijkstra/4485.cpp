#include <iostream>
#include <queue>
#include <stdio.h>
#include <memory.h>
using namespace std;

int map[125][125], d[125][125], visit[125][125];
int x_direct[] = { 0,1,0,-1 }, y_direct[] = { 1,0,-1,0 };
int N;

int Min(int x, int y) {
	return x < y ? x : y;
}

void dijkstra(int x, int y) {
	d[x][y] = map[x][y];
	visit[x][y] = 1;

	priority_queue < pair<int, pair<int, int> > >q;
	q.push(make_pair(-d[x][y], make_pair(x, y)));
	while (!q.empty()) {
		int nowx = q.top().second.first;
		int nowy = q.top().second.second;
		int ans = -q.top().first;
		q.pop();

		if(d[nowx][nowy]) d[nowx][nowy] = Min(ans, d[nowx][nowy]);
		else d[nowx][nowy] = ans;
		visit[nowx][nowy] = 1;

		for (int i = 0; i < 4; i++) {
			int xx = nowx + x_direct[i];
			int yy = nowy + y_direct[i];

			if (xx < 0 || yy < 0 || xx >= N || yy >= N) continue;
			if (visit[xx][yy]) continue;

			int nextans = ans + map[xx][yy];
			q.push(make_pair(-nextans, make_pair(xx, yy)));
		}
	}
}

int main() {
	for (int T = 1; ; T++) {
		scanf("%d", &N);
		if (!N) break;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &map[i][j]);
			}
		}

		dijkstra(0, 0);
		printf("Problem %d: %d\n", T, d[N - 1][N - 1]);
		memset(d, 0, sizeof(d));
		memset(visit, 0, sizeof(visit));
	}

	return 0;
}
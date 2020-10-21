#include <iostream>
#include <queue>
#include <stdio.h>
#include <memory.h>
using namespace std;

char map[30][30][30];
int d[30][30][30], L, R, C;
int x_direct[] = { 1,0,0,-1,0,0 }, y_direct[] = { 0,1,0,0,-1,0 }, z_direct[] = { 0,0,1,0,0,-1 };
int sx, sy, sz, ex, ey, ez;

void dijkstra(int x, int y, int z) {
	d[x][y][z] = 0;
	priority_queue<pair<pair<int, int>, pair<int, int> > > q;
	q.push(make_pair(make_pair(0, x), make_pair(y, z)));
	while (!q.empty()) {
		int nowx = q.top().first.second;
		int nowy = q.top().second.first;
		int nowz = q.top().second.second;
		int sec = -q.top().first.first;
		q.pop();

		if (d[nowx][nowy][nowz]) continue;
		d[nowx][nowy][nowz] = sec;

		for (int i = 0; i < 6; i++) {
			int xx = nowx + x_direct[i];
			int yy = nowy + y_direct[i];
			int zz = nowz + z_direct[i];

			if (xx < 0 || yy < 0 || zz < 0 || xx >= L || yy >= R || zz >= C) continue;
			if (map[xx][yy][zz] == '#') continue;

			int nextsec = sec + 1;
			q.push(make_pair(make_pair(-nextsec, xx), make_pair(yy, zz)));
		}
	}
}

int main() {
	while (1) {
		scanf("%d %d %d", &L, &R, &C);
		if (L == 0) break;
		for (int k = 0; k < L; k++) {
			for (int i = 0; i < R; i++) {
				scanf("%s", map[k][i]);
				for (int j = 0; map[k][i][j]; j++) {
					if (map[k][i][j] == 'E') {
						ex = k;
						ey = i;
						ez = j;
					}
					else if (map[k][i][j] == 'S') {
						sx = k;
						sy = i;
						sz = j;
					}
				}
			}
		}

		dijkstra(sx, sy, sz);
		if (d[ex][ey][ez]) {
			printf("Escaped in %d minute(s).\n", d[ex][ey][ez]);
		}
		else {
			printf("Trapped!\n");
		}

		memset(d, 0, sizeof(d));
	}

	return 0;
}
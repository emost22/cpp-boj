#include <stdio.h>

int map[300][300], visit[300][300], minus[300][300];
int x_direct[] = { 1,-1,0,0 }, y_direct[] = { 0,0,1,-1 };
int N, M, cnt;

void one_year() {
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < M; j++) {
			for (int x = 0; x < 4; x++) {
				int xx = i + x_direct[x];
				int yy = j + y_direct[x];
				if (map[xx][yy] == 0) minus[i][j]++;
			}
		}
	}

	for (int i = 1; i < N; i++) {
		for (int j = 1; j < M; j++) {
			if (map[i][j] > minus[i][j]) map[i][j] -= minus[i][j];
			else map[i][j] = 0;
		}
	}
}

void dfs(int x, int y) {
	visit[x][y] = 1;
	
	for (int i = 0; i < 4; i++) {
		int xx = x + x_direct[i];
		int yy = y + y_direct[i];

		if (xx < 0 || yy < 0 || xx >= N || yy >= M) continue;
		if (!map[xx][yy] || visit[xx][yy]) continue;

		dfs(xx, yy);
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (int Y = 1; ; Y++) {
		one_year();
		memset(visit, 0, sizeof(visit));
		memset(minus, 0, sizeof(minus));
		for (int i = 1; i < N; i++) {
			for (int j = 1; j < M; j++) {
				if (map[i][j] && !visit[i][j]) {
					dfs(i, j);
					cnt++;
				}
			}
		}
		if (cnt > 1) {
			printf("%d\n", Y);
			break;
		}
		if (cnt == 0) break;
		cnt = 0;
	}
	if (cnt == 1 || cnt == 0) printf("0\n");

	return 0;
}
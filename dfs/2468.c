#include <stdio.h>

int map[100][100], visit[100][100];
int x_direct[] = { 1,-1,0,0 }, y_direct[] = { 0,0,1,-1 };
int N, cnt, ans;

int Max(int x, int y) {
	return x > y ? x : y;
}

void dfs(int x, int y, int height) {
	visit[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int xx = x + x_direct[i];
		int yy = y + y_direct[i];

		if (xx < 0 || yy < 0 || xx >= N || yy >= N) continue;
		if (map[xx][yy] <= height || visit[xx][yy]) continue;

		dfs(xx, yy, height);
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 0; i <= 100; i++) {
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < N; y++) {
				if (map[x][y] > i && !visit[x][y]) {
					dfs(x, y, i);
					cnt++;
				}
			}
		}
		ans = Max(ans, cnt);
		if (cnt == 0) break;
		cnt = 0;
		memset(visit, 0, sizeof(visit));
	}

	printf("%d\n", ans);

	return 0;
}
#include <stdio.h>

int forest[501][501], dp[501][501];
int x_direct[] = { 1,-1,0,0 }, y_direct[] = { 0,0,1,-1 };
int N, max_live;

int Max(int x, int y) {
	return x > y ? x : y;
}

int DFS(int x, int y) {
	if (dp[x][y]) return dp[x][y];

	dp[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int xx = x + x_direct[i];
		int yy = y + y_direct[i];

		if (xx <= 0 || xx > N || yy <= 0 || yy > N) continue;
		if (forest[x][y] >= forest[xx][yy]) continue;

		dp[x][y] = Max(dp[x][y], DFS(xx, yy) + 1);
 	}

	return dp[x][y];
}

int main() {
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &forest[i][j]);
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			max_live = Max(max_live, DFS(i, j));
		}
	}

	printf("%d\n", max_live);

	return 0;
}
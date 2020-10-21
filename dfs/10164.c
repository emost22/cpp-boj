#include <stdio.h>

int dp[16][16];
int x_direct[] = { 1,0 }, y_direct[] = { 0,1 };
int N, M;

int DFS(int x, int y, int ex, int ey) {
	if (dp[x][y]) return dp[x][y];
	if (x == ex && y == ey) return 1;

	for (int i = 0; i < 2; i++) {
		int xx = x + x_direct[i];
		int yy = y + y_direct[i];

		if (xx > ex || yy > ey) continue;

		dp[x][y] += DFS(xx, yy, ex, ey);
	}

	return dp[x][y];
}

int main() {
	int N, M, K; // N->s, M->e

	scanf("%d %d %d", &N, &M, &K);

	if (K == 0) {
		printf("%d\n", DFS(1, 1, N, M));
	}
	else if (K % M == 0) {
		printf("%d\n", DFS(1, 1, K / M, M));
	}
	else {
		printf("%d\n", DFS(1, 1, K / M + 1, K % M) * DFS(K / M + 1, K % M, N, M));
	}

	return 0;
}
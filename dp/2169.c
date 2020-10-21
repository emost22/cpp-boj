#include <stdio.h>

int map[1001][1001], dp[1001][1001], line[1001];
int N, M;

int Max(int x, int y) {
	return x > y ? x : y;
}

int find() {
	dp[1][1] = map[1][1];
	for (int i = 2; i <= M; i++) {
		dp[1][i] = dp[1][i - 1] + map[1][i];
	}

	for (int i = 2; i <= N; i++) {
		dp[i][1] = dp[i - 1][1] + map[i][1];
		for (int j = 2; j <= M; j++) {
			dp[i][j] = Max(dp[i - 1][j], dp[i][j - 1]) + map[i][j];
		}

		line[M] = dp[i - 1][M] + map[i][M];
		for (int j = M - 1; j > 0; j--) {
			line[j] = Max(line[j + 1], dp[i - 1][j]) + map[i][j];
		}

		for (int j = 1; j <= M; j++) {
			dp[i][j] = Max(dp[i][j], line[j]);
		}
	}

	return dp[N][M];
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	printf("%d\n", find());

	return 0;
}
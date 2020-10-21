#include <stdio.h>

int line[100001][3], dp[100001][3];
int max_score, min_score;

int Max(int x, int y) {
	return x > y ? x : y;
}

int Min(int x, int y) {
	return x < y ? x : y;
}

int main() {
	int N;

	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d %d %d", &line[i][0], &line[i][1], &line[i][2]);

		dp[i][0] = Max(dp[i - 1][0], dp[i - 1][1]) + line[i][0];
		dp[i][1] = Max(dp[i][0] - line[i][0], dp[i - 1][2]) + line[i][1];
		dp[i][2] = Max(dp[i - 1][1], dp[i - 1][2]) + line[i][2];
	}
	max_score = Max(Max(dp[N][0], dp[N][1]), dp[N][2]);

	for (int i = 1; i <= N; i++) {
		dp[i][0] = Min(dp[i - 1][0], dp[i - 1][1]) + line[i][0];
		dp[i][1] = Min(dp[i][0] - line[i][0], dp[i - 1][2]) + line[i][1];
		dp[i][2] = Min(dp[i - 1][1], dp[i - 1][2]) + line[i][2];
	}
	min_score = Min(Min(dp[N][0], dp[N][1]), dp[N][2]);

	printf("%d %d\n", max_score, min_score);

	return 0;
}
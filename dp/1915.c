#include <stdio.h>

int dp[1001][1001], max_value;

int Max(int x, int y) {
	return x > y ? x : y;
}

int Min(int x, int y, int z) {
	return x < y ? (x < z ? x : z) : (y < z ? y : z);
}

int main() {
	int N, M;
	char c[1001];

	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		scanf("%s", c);
		for (int j = 1; j <= M; j++) {
			dp[i][j] = c[j - 1] - 48;
			if (dp[i][j] > 0) {
				dp[i][j] = Min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]) + 1;
				max_value = Max(max_value, dp[i][j]);
			}
		}
	}

	printf("%d\n", max_value * max_value);

	return 0;
}
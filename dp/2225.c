#include <stdio.h>

long long int dp[201][201]; //dp[K][N]

int main() {
	int N, K;

	scanf("%d %d", &N, &K);

	for (int i = 0; i <= N; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= K; i++) {
		for (int j = 0; j <= N; j++) {
			for (int k = 0; k <= j; k++) {
				dp[i][j] = (dp[i][j] + dp[i - 1][k]) % 1000000000;
			}
		}
	}

	printf("%d\n", dp[K][N]);

	return 0;
}
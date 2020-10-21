#include <stdio.h>

int dp[1001][10];
int sum;

int find(int N) {
	for (int i = 0; i <= 9; i++) dp[1][i] = 1;

	for (int i = 2; i <= N; i++) {
		dp[i][0] = 1;
		for (int j = 1; j <= 9; j++) {
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 10007;
		}
	}

	for(int i=0; i<=9; i++) sum = (sum + dp[N][i]) % 10007;

	return sum;
}

int main() {
	int N;

	scanf("%d", &N);

	printf("%d\n", find(N));

	return 0;
}
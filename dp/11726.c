#include <stdio.h>

int dp[1001];

int find(int N) {
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= N; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	}

	return dp[N];
}

int main() {
	int N;

	scanf("%d", &N);

	printf("%d\n", find(N));

	return 0;
}
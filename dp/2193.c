#include <stdio.h>

long long int dp[91];

long long int find(int N) {
	dp[1] = 1;
	dp[2] = 1;
	for (int i = 3; i <= N; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	return dp[N];
}

int main() {
	int N;

	scanf("%d", &N);

	printf("%lld\n", find(N));

	return 0;
}
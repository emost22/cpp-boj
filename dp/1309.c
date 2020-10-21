#include <stdio.h>
#define mod 9901

int dp[100001];

int find(int N) {
	dp[1] = 3;
	dp[2] = 7;
	for (int i = 3; i <= N; i++) {
		dp[i] = (dp[i - 1] + dp[i - 1] + dp[i - 2]) % mod;
	}

	return dp[N];
}

int main() {
	int N;

	scanf("%d", &N);

	printf("%d\n", find(N));

	return 0;
}
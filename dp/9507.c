#include <stdio.h>

long long int dp[68];

long long int koong(int N) {
	if (N < 2) return dp[N] = 1;
	if (N == 2) return dp[N] = 2;
	if (N == 3) return dp[N] = 4;
	if (dp[N]) return dp[N];

	return dp[N] = koong(N - 1) + koong(N - 2) + koong(N - 3) + koong(N - 4);
}

int main() {
	int Testcase, N;

	scanf("%d", &Testcase);

	for (int T = 0; T < Testcase; T++) {
		scanf("%d", &N);

		printf("%lld\n", koong(N));
	}

	return 0;
}
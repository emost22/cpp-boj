#include <stdio.h>

long long int list[41], dp[41];
long long int mul = 1;

void fibo(int N) {
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= N; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
}

int main() {
	int N, M;

	scanf("%d", &N);

	fibo(N);
	
	scanf("%d", &M);
	for (int i = 1; i <= M; i++) {
		scanf("%lld", &list[i]);

		mul *= dp[list[i] - list[i - 1] - 1];
	}
	mul *= dp[N - list[M]];

	printf("%lld\n", mul);

	return 0;
}
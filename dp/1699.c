#include <stdio.h>

int dp[100001];

int Min(int x, int y) {
	return x < y ? x : y;
}

int main() {
	int N;

	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		dp[i] = i;

		for (int j = 1; j * j <= i; j++) {
			dp[i] = Min(dp[i], dp[i - j * j] + 1);
		}
	}

	printf("%d\n", dp[N]);

	return 0;
}
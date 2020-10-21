#include <stdio.h>

int work[2][16], dp[16];

int Max(int x, int y) {
	return x > y ? x : y;
}

int find(int N) {
	if (work[0][N] == 1) dp[N] = work[1][N];

	for (int i = N - 1; i > 0; i--) {
		if (i + work[0][i] <= N + 1) {
			dp[i] = Max(work[1][i] + dp[i + work[0][i]], dp[i + 1]);
		}
		else dp[i] = dp[i + 1];
	}

	return dp[1];
}

int main() {
	int N;

	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &work[0][i], &work[1][i]);		
	}

	printf("%d\n", find(N));

	return 0;
}
#include <stdio.h>
#define INF 1000000000

int coin[100], dp[10001];

int Min(int x, int y) {
	return x < y ? x : y;
}

int main() {
	int N, K;

	scanf("%d %d", &N, &K);

	for (int i = 1; i <= K; i++) {
		dp[i] = INF;
	}

	for (int i = 0; i < N; i++) {
		scanf("%d", &coin[i]);

		for (int j = coin[i]; j <= K; j++) {
			dp[j] = Min(dp[j], dp[j - coin[i]] + 1);
		}
	}

	if (dp[K] == INF) printf("-1\n");
	else printf("%d\n", dp[K]);

	return 0;
}
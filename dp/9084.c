#include <stdio.h>

int coin[20], dp[10001];

int main() {
	int Testcase, N, M;
	scanf("%d", &Testcase);
	while (Testcase--) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d", &coin[i]);
		}
		scanf("%d", &M);

		dp[0] = 1;
		for (int i = 0; i < N; i++) {
			for (int j = coin[i]; j <= M; j++) {
				dp[j] += dp[j - coin[i]];
			}
		}

		printf("%d\n", dp[M]);
		memset(dp, 0, sizeof(dp));
	}

	return 0;
}
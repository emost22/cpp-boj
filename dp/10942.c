#include <stdio.h>

int list[2001], dp[2001][2001];

void find(int N) {
	for (int i = 2; i <= N - 1; i++) {
		for (int j = 1; j <= N - i; j++) {
			if (list[j] == list[j + i] && dp[j + 1][j + i - 1]) {
				dp[j][j + i] = 1;
			}
		}
	}
}

int main() {
	int N, M, s, e;

	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &list[i]);

		dp[i][i] = 1;
		if (list[i] == list[i - 1]) {
			dp[i - 1][i] = 1;
		}
	}
	
	find(N);

	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &s, &e);

		printf("%d\n", dp[s][e]);
	}

	return 0;
}
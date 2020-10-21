#include <stdio.h>

int list[1001], dp[1001];

int Min(int x, int y) {
	return x < y ? x : y;
}

int find(int N) {
	dp[1] = 0;
	for (int i = 1; i < N; i++) {
		if (list[i]) {
			for (int j = 1; j <= list[i]; j++) {
				if (i + j > N) break;
				dp[i + j] = Min(dp[i + j], dp[i] + 1);
			}
		}
	}

	return dp[N];
}

int main() {
	int N;

	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &list[i]);
		dp[i] = 10000000;
	}

	if (find(N) == 10000000) printf("-1\n");
	else printf("%d\n", dp[N]);

	return 0;
}
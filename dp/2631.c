#include <stdio.h>

int list[201], dp[201];
int LIS;

int Max(int x, int y) {
	return x > y ? x : y;
}

int main() {
	int N;

	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &list[i]);

		for (int j = 0; j < i; j++) {
			if (list[j] < list[i] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
			}
		}

		LIS = Max(LIS, dp[i]);
	}

	printf("%d\n", N - LIS);

	return 0;
}
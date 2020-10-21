#include <stdio.h>

int num[1001], dp[1001], length;

int Max(int x, int y) {
	return x > y ? x : y;
}

int main() {
	int N;

	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &num[i]);

		for (int j = 0; j < i; j++) {
			if (num[i] < num[j] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
			}
		}

		length = Max(length, dp[i]);
	}

	printf("%d\n", length + 1);

	return 0;
}
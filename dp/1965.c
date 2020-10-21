#include <stdio.h>

int box[1001], dp[1001];
int num;

int Max(int x, int y) {
	return x > y ? x : y;
}

int main() {
	int N;

	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &box[i]);

		for (int j = 0; j < i; j++) {
			if (box[i] > box[j] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
			}
		}
		num = Max(num, dp[i]);
	}

	printf("%d\n", num);

	return 0;
}
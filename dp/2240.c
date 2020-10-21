#include <stdio.h>

int list[1001], dp[1001][31], max_cnt;

int Max(int x, int y) {
	return x > y ? x : y;
}

int find(int t, int w) {
	for (int i = 1; i <= t; i++) {
		if (list[i] == 1) {
			dp[i][0] = dp[i - 1][0] + 1;
		}
		else {
			dp[i][0] = dp[i - 1][0];
		}

		for (int j = 1; j <= w; j++) {
			if (j % 2 == 0) { //현재 1번나무
				if (list[i] == 1) {
					dp[i][j] = Max(dp[i - 1][j], dp[i - 1][j - 1]) + 1;
				}
				else {
					dp[i][j] = Max(dp[i - 1][j], dp[i - 1][j - 1]);
				}
			}
			else { //현재 2번나무
				if (list[i] == 1) {
					dp[i][j] = Max(dp[i - 1][j], dp[i - 1][j - 1]);
				}
				else {
					dp[i][j] = Max(dp[i - 1][j], dp[i - 1][j - 1]) + 1;
				}
			}

			max_cnt = Max(max_cnt, dp[i][j]);
		}
		max_cnt = Max(max_cnt, dp[i][0]);
	}

	return max_cnt;
}

int main() {
	int T, W;
	scanf("%d %d", &T, &W);
	for (int i = 1; i <= T; i++) {
		scanf("%d", &list[i]);
	}

	printf("%d\n", find(T, W));

	return 0;
}
#include <stdio.h>

int dp[31][31];

int find(int x, int y) {
	for (int i = 0; i <= y; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 1)
				dp[i][j] = i;
			else if (j == i || j == 0) 
				dp[i][j] = 1;
			else 
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];

			if (i == y && j == x) break;
		}
	}

	return dp[y][x];
}

int main() {
	int Testcase, x, y;

	scanf("%d", &Testcase);

	for (int T = 0; T < Testcase; T++) {
		scanf("%d %d", &x, &y);

		printf("%d\n", find(x, y));
	}

	return 0;
}
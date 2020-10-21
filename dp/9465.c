#include <stdio.h>

int score[2][100001], dp[2][100001];

int Max(int x, int y) {
	return x > y ? x : y;
}

int find(int N) {
	dp[0][1] = score[0][1];
	dp[1][1] = score[1][1];
	for (int i = 2; i <= N; i++) {
		dp[0][i] = Max(dp[1][i - 1], dp[1][i - 2]) + score[0][i];
		dp[1][i] = Max(dp[0][i - 1], dp[0][i - 2]) + score[1][i];
	}

	return Max(dp[0][N], dp[1][N]);
}

int main() {
	int Testcase, N;

	scanf("%d", &Testcase);

	for (int T = 0; T < Testcase; T++) {
		scanf("%d", &N);

		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= N; j++) {
				scanf("%d", &score[i][j]);
			}
		}

		printf("%d\n", find(N));
	}

	return 0;
}
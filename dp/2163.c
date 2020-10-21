#include <stdio.h>

int dp[301][301];

int find(int x, int y) {
	dp[1][y] = y - 1;
	for (int i = 2; i <= x; i++) {
		dp[i][y] = dp[i - 1][y] + y;
	}

	return dp[x][y];
}

int main() {
	int N, M;

	scanf("%d %d", &N, &M);

	if (N > M) printf("%d\n", find(N, M));
	else printf("%d\n", find(M, N));

	return 0;
}
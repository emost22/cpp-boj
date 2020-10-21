#include <stdio.h>

long long int game[101][101], dp[101][101], visit[101][101];
int N;

long long int DFS(int x, int y) {
	if (x == N && y == N) return 1;
	if (visit[x][y]) return dp[x][y];

	visit[x][y] = 1;

	if (y + game[x][y] <= N) dp[x][y] += DFS(x, y + game[x][y]);
	if (x + game[x][y] <= N) dp[x][y] += DFS(x + game[x][y], y);

	return dp[x][y];
}

int main() {
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%lld", &game[i][j]);
		}
	}

	printf("%lld\n", DFS(1, 1));

	return 0;
}
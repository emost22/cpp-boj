#include <stdio.h>

char str[20], table[20][20], Queue[26];
int dp[20][20];
int x_direct[] = { 1,-1,0,0 }, y_direct[] = { 0,0,1,-1 };
int R, C, index, check, now;

int Max(int x, int y) {
	return x > y ? x : y;
}

int dfs(int x, int y) {
	Queue[index++] = table[x][y];
	dp[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int xx = x + x_direct[i];
		int yy = y + y_direct[i];

		if (xx < 0 || yy < 0 || xx >= R || yy >= C) continue;
		if (strchr(Queue, table[xx][yy])) continue;

		dp[x][y] = Max(dp[x][y], dfs(xx, yy) + 1);
	}
	index--;
	Queue[index] = 0;
	return dp[x][y];
}

int main() {
	scanf("%d %d", &R, &C);
	for (int i = 0; i < R; i++) {
		scanf("%s", str);
		for (int j = 0; str[j]; j++) {
			table[i][j] = str[j];
		}
	}

	printf("%d\n", dfs(0,0));

	return 0;
}
#include <stdio.h>

char map[100][100];
int visit1[100][100], visit2[100][100], ans1, ans2;
int x_direct[] = { 1,-1,0,0 }, y_direct[] = { 0,0,1,-1 };
int N;

void dfs1(int x, int y, char ch) {
	visit1[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int xx = x + x_direct[i];
		int yy = y + y_direct[i];

		if (xx < 0 || yy < 0 || xx >= N || yy >= N) continue;
		if (ch != map[xx][yy] || visit1[xx][yy]) continue;

		dfs1(xx, yy, ch);
	}
}

void dfs2(int x, int y, char ch) {
	visit2[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int xx = x + x_direct[i];
		int yy = y + y_direct[i];

		if (xx < 0 || yy < 0 || xx >= N || yy >= N) continue;
		if (ch == 'B') {
			if (ch != map[xx][yy] || visit2[xx][yy]) continue;
		}
		else {
			if (map[xx][yy] == 'B' || visit2[xx][yy]) continue;
		}

		dfs2(xx, yy, ch);
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s", map[i]);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visit1[i][j]) {
				dfs1(i, j, map[i][j]);
				ans1++;
			}
			if (!visit2[i][j]) {
				dfs2(i, j, map[i][j]);
				ans2++;
			}
		}
	}

	printf("%d %d\n", ans1, ans2);

	return 0;
}
#include <stdio.h>

int field[50][50], visit[50][50];
int x_direct[] = { 1,-1,0,0 }, y_direct[] = { 0,0,1,-1 };
int Testcase, M, N, K, X, Y, cnt;

void dfs(int x, int y) {
	visit[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int xx = x + x_direct[i];
		int yy = y + y_direct[i];

		if (xx < 0 || yy < 0 || xx >= N || yy >= M) continue;
		if (!field[xx][yy] || visit[xx][yy]) continue;

		dfs(xx, yy);
	}
}

int main() {
	scanf("%d", &Testcase);

	for (int T = 0; T < Testcase; T++) {
		scanf("%d %d %d", &M, &N, &K);
		for (int i = 0; i < K; i++) {
			scanf("%d %d", &X, &Y);
			field[Y][X] = 1;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (field[i][j] && !visit[i][j]) {
					dfs(i, j);
					cnt++;
				}
			}
		}

		printf("%d\n", cnt);
		cnt = 0;
		memset(field, 0, sizeof(field));
		memset(visit, 0, sizeof(visit));
	}

	return 0;
}
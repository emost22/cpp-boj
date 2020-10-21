#include <stdio.h>

int map[100][100], visit[100][100], sol[5000], sorted[5000];
int x_direct[] = { 1,-1,0,0 }, y_direct[] = { 0,0,1,-1 };
int M, N, K, sx, sy, ex, ey, ans, cnt;

void merge(int s, int m, int e) {
	int i, j, k;
	i = s;
	k = s;
	j = m + 1;

	while (i <= m && j <= e) {
		if (sol[i] < sol[j]) {
			sorted[k++] = sol[i++];
		}
		else sorted[k++] = sol[j++];
	}

	if (i > m) for (int t = j; t <= e; t++) sorted[k++] = sol[t];
	else for (int t = i; t <= m; t++) sorted[k++] = sol[t];
	for (int t = s; t <= e; t++) sol[t] = sorted[t];
}

void mergesort(int s, int e) {
	if (s < e) {
		int m = (s + e) / 2;
		mergesort(s, m);
		mergesort(m + 1, e);
		merge(s, m, e);
	}
}

void paint() {
	for (int i = sx; i < ex; i++) {
		for (int j = sy; j < ey; j++) {
			map[i][j] = 1;
		}
	}
}

void dfs(int x, int y) {
	visit[x][y] = 1;
	cnt++;
	for (int i = 0; i < 4; i++) {
		int xx = x + x_direct[i];
		int yy = y + y_direct[i];

		if (xx < 0 || yy < 0 || xx >= N || yy >= M) continue;
		if (map[xx][yy] || visit[xx][yy]) continue;

		dfs(xx, yy);
	}
}

int main() {
	scanf("%d %d %d", &M, &N, &K);
	while (K--) {
		scanf("%d %d %d %d", &sx, &sy, &ex, &ey);

		paint();
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!map[i][j] && !visit[i][j]) {
				dfs(i, j);
				sol[ans++] = cnt;
				cnt = 0;
			}
		}
	}
	mergesort(0, ans - 1);
	printf("%d\n", ans);
	for (int i = 0; i < ans; i++) {
		printf("%d ", sol[i]);
	}
	printf("\n");

	return 0;
}
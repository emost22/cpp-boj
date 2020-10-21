#include <stdio.h>

int graph[100][100], visit[100][100], N;

void dfs(int v, int x, int y) {
	visit[v][y] = 1;
	graph[v][y] = 1;

	for (int i = 0; i < N; i++) {
		if (graph[y][i] && !visit[v][i]) {
			dfs(v, y, i);
		}
	}
}

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &graph[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (graph[i][j] && !visit[i][j]) {
				dfs(i, i, j);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", graph[i][j]);
		}
		printf("\n");
	}

	return 0;
}
#include <stdio.h>

int graph[1001][1001], visit[1001];
int N, M, U, V, cnt;

void dfs(int v) {
	visit[v] = 1;

	for (int i = 1; i <= N; i++) {
		if (graph[v][i] && !visit[i]) {
			dfs(i);
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &U, &V);

		graph[U][V] = 1;
		graph[V][U] = 1;
	}

	for (int i = 1; i <= N; i++) {
		if (!visit[i]) {
			dfs(i);
			cnt++;
		}
	}

	printf("%d\n", cnt);

	return 0;
}
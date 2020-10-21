#include <stdio.h>

int graph[1001][1001], visit_dfs[1001], visit_bfs[1001], Queue[1001];
int N, M, V;

void dfs(int n) {
	visit_dfs[n] = 1;
	printf("%d ", n);

	for (int i = 1; i <= N; i++) {
		if (graph[i][n] && !visit_dfs[i]) {
			dfs(i);
		}
	}
}

void bfs(int n) {
	int cnt = 0, now = 0, v;
	Queue[cnt++] = n;
	visit_bfs[n] = 1;
	
	while (1) {
		v = Queue[now++];
		printf("%d ", v);
		for (int i = 1; i <= N; i++) {
			if (graph[i][v] && !visit_bfs[i]) {
				Queue[cnt++] = i;
				visit_bfs[i] = 1;
			}
		}
		if (now == cnt) break;
	}
}

int main() {
	int a, b;

	scanf("%d %d %d", &N, &M, &V);

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	dfs(V);
	printf("\n");
	bfs(V);
	printf("\n");

	return 0;
}
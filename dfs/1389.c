#include <stdio.h>

int graph[101][101], visit[101], conn[101], Queue[101];
int N, M, A, B, index, now, min_value, sum[101];

int Min(int x, int y) {
	return sum[x] <= sum[y] ? x : y;
}

void bfs(int v) {
	int a;
	visit[v] = 1;
	Queue[index++] = v;
	while (1) {
		a = Queue[now++];
		for (int i = 1; i <= N; i++) {
			if (!visit[i] && graph[a][i]) {
				Queue[index++] = i;
				visit[i] = 1;
				conn[i] = conn[a] + 1;
			}
		}
		if (index == now) break;
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &A, &B);
		graph[A][B] = 1;
		graph[B][A] = 1;
	}
	sum[0] = 111111111;
	for (int i = 1; i <= N; i++) {
		bfs(i);
		for (int j = 1; j <= N; j++) sum[i] += conn[j];
		min_value = Min(min_value, i);
		index = 0;
		now = 0;
		memset(visit, 0, sizeof(visit));
		memset(conn, 0, sizeof(conn));
	}

	printf("%d\n", min_value);

	return 0;
}
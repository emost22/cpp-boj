#include <stdio.h>

int graph[401][401];
int N, K, S, s, e;

int main() {
	scanf("%d %d", &N, &K);
	for (int i = 1; i <= K; i++) {
		scanf("%d %d", &s, &e);

		graph[s][e] = -1;
		graph[e][s] = 1;
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (graph[i][k] == -1 && graph[k][j] == -1) {
					graph[i][j] = -1;
					graph[j][i] = 1;
				}
			}
		}
	}

	scanf("%d", &S);
	while (S--) {
		scanf("%d %d", &s, &e);

		printf("%d\n", graph[s][e]);
	}

	return 0;
}
#include <stdio.h>

int graph[100001], visit[100001], check[100001];
int N, cnt;

void dfs(int v) {
	visit[v] = 1;

	if (!visit[graph[v]]) {
		dfs(graph[v]);
	}
	else if (!check[graph[v]]) {
		for (int i = graph[v]; i != v; i = graph[i]) {
			cnt++;
		}
		cnt++;
	}
	check[v] = 1;
}

int main() {
	int Testcase;

	scanf("%d", &Testcase);
	while (Testcase--) {
		scanf("%d", &N);
		for (int i = 1; i <= N; i++) {
			scanf("%d", &graph[i]);
		}

		for (int i = 1; i <= N; i++) {
			if (!visit[i]) {
				dfs(i);
			}
		}

		printf("%d\n", N - cnt);
		cnt = 0;
		memset(visit, 0, sizeof(visit));
		memset(check, 0, sizeof(check));
	}

	return 0;
}
#include <stdio.h>

int graph[101], visit[101], check[101], list[101], sorted[101];
int N, cnt;

void merge(int s, int m, int e) {
	int i, j, k;
	i = s, k = s, j = m + 1;

	while (i <= m && j <= e) {
		if (list[i] < list[j]) {
			sorted[k++] = list[i++];
		}
		else sorted[k++] = list[j++];
	}

	if (i > m) for (int t = j; t <= e; t++) {
		sorted[k++] = list[t];
	}
	else for (int t = i; t <= m; t++) {
		sorted[k++] = list[t];
	}
	for (int t = s; t <= e; t++) list[t] = sorted[t];
}

void mergesort(int s, int e) {
	if (s < e) {
		int m = (s + e) / 2;
		mergesort(s, m);
		mergesort(m + 1, e);
		merge(s, m, e);
	}
}

void dfs(int v) {
	visit[v] = 1;

	if (!visit[graph[v]]) {
		dfs(graph[v]);
	}
	else if (!check[graph[v]]) {
		for (int i = graph[v]; i != v; i = graph[i]) {
			list[cnt++] = i;
		}
		list[cnt++] = v;
	}
	check[v] = 1;
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &graph[i]);
	}

	for (int i = 1; i <= N; i++) {
		dfs(i);
		memset(visit, 0, sizeof(visit));
	}

	mergesort(0, cnt - 1);
	printf("%d\n", cnt);
	for (int i = 0; i < cnt; i++) {
		printf("%d\n", list[i]);
	}

	return 0;
}
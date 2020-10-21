#include <stdio.h>

int list[13], ans[6];
int N, index;

void dfs(int v) {
	if (index == 6) {
		for (int i = 0; i < index; i++) {
			printf("%d ", ans[i]);
		}
		printf("\n");
		return;
	}

	for (int i = v; i < N; i++) {
		ans[index++] = list[i];
		dfs(i + 1);
		index--;
	}
}

int main() {
	while (1) {
		scanf("%d", &N);
		if (!N) break;

		for (int i = 0; i < N; i++) {
			scanf("%d", &list[i]);
		}

		dfs(0);
		printf("\n");
		index = 0;
	}

	return 0;
}
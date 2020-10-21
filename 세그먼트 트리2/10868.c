#include <stdio.h>

long long int list[100001], tree[400004];

long long int Min(long long int x, long long int y) {
	return x < y ? x : y;
}

long long int init(long long int list[], long long int tree[], int node, int start, int end) {
	if (start == end)
		return tree[node] = list[start];

	int middle = (start + end) / 2;

	return tree[node] = Min(init(list, tree, node * 2, start, middle), init(list, tree, node * 2 + 1, middle + 1, end));
}

long long int find_min(long long int tree[], int node, int start, int end, int left, int right) {
	if (right < start || end < left)
		return 1111111111;
	if (left <= start && end <= right)
		return tree[node];

	int middle = (start + end) / 2;

	return Min(find_min(tree, node * 2, start, middle, left, right), find_min(tree, node * 2 + 1, middle + 1, end, left, right));
}

int main() {
	int N, M, left, right;

	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &list[i]);
	}

	init(list, tree, 1, 1, N);

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &left, &right);

		printf("%lld\n", find_min(tree, 1, 1, N, left, right));
	}

	return 0;
}
#include <stdio.h>

long long int list[1000001], tree[4000004];

long long int init(long long int arr[], long long int tree[], int node, int start, int end) {
	if (start == end)
		return tree[node] = arr[start];

	int middle = (start + end) / 2;

	return tree[node] = init(arr, tree, node * 2, start, middle) + init(arr, tree, node * 2 + 1, middle + 1, end);
}

void update(long long int tree[], int node, int index, int start, int end, long long int diff) {
	if (index < start || end < index)
		return;

	tree[node] += diff;

	if (start != end) {
		int middle = (start + end) / 2;
		update(tree, node * 2, index, start, middle, diff);
		update(tree, node * 2 + 1, index, middle + 1, end, diff);
	}
}

long long int sum(long long int tree[], int node, int start, int end, int left, int right) {
	if (right < start || end < left)
		return 0;

	if (left <= start && end <= right)
		return tree[node];

	int middle = (start + end) / 2;
	return sum(tree, node * 2, start, middle, left, right) + sum(tree, node * 2 + 1, middle + 1, end, left, right);
}

int main() {
	int N, M, K, a, b, c;

	scanf("%d %d %d", &N, &M, &K);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &list[i]);
	}

	init(list, tree, 1, 1, N);

	for (int i = 0; i < (M + K); i++) {
		scanf("%d %d %d", &a, &b, &c);

		if (a == 1) {
			update(tree, 1, b, 1, N, c - list[b]);
			list[b] = c;
		}
		else {
			printf("%lld\n", sum(tree, 1, 1, N, b, c));
		}
	}

	return 0;
}
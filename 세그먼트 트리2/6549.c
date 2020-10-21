#include <stdio.h>

long long int list[100001], tree[400004];
long long int max_value;
int N;

long long int Max(long long int x, long long int y) {
	return x >= y ? x : y;
}

long long int Min(long long int x, long long int y) {
	return list[x] <= list[y] ? x : y;
}

long long int init(int node, int start, int end) {
	if (start == end)
		return tree[node] = start;

	int middle = (start + end) / 2;
	int left = init(node * 2, start, middle);
	int right = init(node * 2 + 1, middle + 1, end);

	return tree[node] = Min(left, right);
}

int find_index(int node, int start, int end, int i, int j) {
	if (i > end || j < start)
		return 0;

	if (i <= start && end <= j)
		return tree[node];

	int middle = (start + end) / 2;
	int m1 = find_index(node * 2, start, middle, i, j);
	int m2 = find_index(node * 2 + 1, middle + 1, end, i, j);

	if (m1 == 0) return m2;
	else if (m2 == 0) return m1;
	else {
		if (list[m1] <= list[m2]) return m1;
		else return m2;
	}
}

long long int find_maxarea(int start, int end) {
	int index = find_index(1, 1, N, start, end);

	long long int area = (long long int)((end - start + 1)*list[index]);

	if (start <= index - 1) {
		long long int temp = find_maxarea(start, index - 1);
		area = Max(area, temp);
	}
	
	if (index + 1 <= end) {
		long long int temp = find_maxarea(index + 1, end);
		area = Max(area, temp);
	}

	return area;
}

int main() {

	while (1) {
		scanf("%d", &N);
		if (N == 0) break;
		for (int i = 1; i <= N; i++) {
			scanf("%lld", &list[i]);
		}

		init(1, 1, N);

		printf("%lld\n", find_maxarea(1, N));
	}

	return 0;
}
#include <iostream>
#include <algorithm>
#define MAX 200001
using namespace std;

int list[MAX];
int tree[MAX << 2];
int lazy[MAX << 2];
int N, M;

void lazyUpdate(int node, int l, int r) {
	if (!lazy[node]) return;
	tree[node] += lazy[node];
	if (l != r) {
		lazy[node << 1] += lazy[node];
		lazy[(node << 1) + 1] += lazy[node];
	}
	lazy[node] = 0;
}

int update(int node, int l, int r, int s, int e, int diff) {
	lazyUpdate(node, l, r);
	if (l > e || s > r) return tree[node];
	if (s <= l && r <= e) {
		lazy[node] += diff;
		lazyUpdate(node, l, r);
		return tree[node];
	}

	int m = (l + r) >> 1;
	return tree[node] = min(update(node << 1, l, m, s, e, diff), update((node << 1) + 1, m + 1, r, s, e, diff));
}

int query(int node, int l, int r, int s, int e) {
	lazyUpdate(node, l, r);
	if (l > e || s > r) return 0;
	if (s <= l && r <= e) return tree[node];

	int m = (l + r) >> 1;
	return min(query(node << 1, l, m, s, e), query((node << 1) + 1, m + 1, r, s, e));
}

void init() {
	for (int i = 1; i <= N; i++) {
		update(1, 1, N, i, N, 1);
	}

	for (int i = 0; i < N; i++) {
		update(1, 1, N, list[i], N, -1);
	}
}

void print() {
	if (query(1, 1, N, 1, N) >= 0) cout << "TAK\n";
	else cout << "NIE\n";
}

void func() {
	init();
	print();

	int idx, x;
	while (M--) {
		cin >> idx >> x;
		update(1, 1, N, list[idx - 1], N, 1);
		update(1, 1, N, x, N, -1);
		list[idx - 1] = x;
		print();
	}
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
	cin >> M;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
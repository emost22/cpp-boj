#include <iostream>
#define MAX 100001
using namespace std;

int tree[MAX * 4], lazy[MAX * 4];
int N;

void lazyUpdate(int node, int s, int e) {
	if (!lazy[node]) return;

	tree[node] += lazy[node];
	if (s != e) {
		lazy[node * 2] += lazy[node];
		lazy[node * 2 + 1] += lazy[node];
	}
	lazy[node] = 0;
}

void update(int node, int s, int e, int l, int r) {
	lazyUpdate(node, s, e);
	if (s > r || l > e) return;
	if (l <= s && e <= r) {
		lazy[node] += 1;
		lazyUpdate(node, s, e);
		return;
	}

	int m = (s + e) / 2;
	update(node * 2, s, m, l, r);
	update(node * 2 + 1, m + 1, e, l, r);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int node, int s, int e, int idx) {
	lazyUpdate(node, s, e);
	if (idx < s || e < idx) return 0;
	if (s == e) {
		int ret = tree[node];
		tree[node] = 0;
		return ret;
	}

	int m = (s + e) / 2;
	return query(node * 2, s, m, idx) + query(node * 2 + 1, m + 1, e, idx);
}

void func() {
	int l, r;
	for (int i = 0; i < N; i++) {
		cin >> l >> r;
		cout << query(1, 1, MAX - 1, l) + query(1, 1, MAX - 1, r) << '\n';

		update(1, 1, MAX - 1, l + 1, r - 1);
	}
}

void input() {
	cin >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
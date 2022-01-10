#include <iostream>
#include <algorithm>
#define MAX 100002
using namespace std;

int lazy[MAX * 4], tree[MAX * 4], list[MAX];
int N, M;

void updateLazy(int node, int s, int e) {
	if (!lazy[node]) return;

	tree[node] += lazy[node];
	if (s != e) {
		lazy[node * 2] += lazy[node];
		lazy[node * 2 + 1] += lazy[node];
	}
	lazy[node] = 0;
}

int update(int node, int s, int e, int l, int r, int diff) {
	updateLazy(node, s, e);
	if (s > r || e < l) return tree[node];
	
	if (l <= s && e <= r) {
		tree[node] += diff;
		if (s != e) {
			lazy[node * 2] += diff;
			lazy[node * 2 + 1] += diff;
		}
		
		return tree[node];
	}

	int m = (s + e) / 2;
	return tree[node] = update(node * 2, s, m, l, r, diff) + update(node * 2 + 1, m + 1, e, l, r, diff);
}

int query(int node, int s, int e, int idx) {
	updateLazy(node, s, e);
	if (s > idx || idx > e) return 0;
	if (s == e) {
		return tree[node];
	}

	int m = (s + e) / 2;
	return query(node * 2, s, m, idx) + query(node * 2 + 1, m + 1, e, idx);
}

void func() {
	int l, r, x;
	while (M--) {
		cin >> l >> r >> x;
		update(1, 1, N, l, r, x);
	}

	for (int i = 1; i <= N; i++) {
		cout << list[i] + query(1, 1, N, i) << ' ';
	}
	cout << '\n';
}

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
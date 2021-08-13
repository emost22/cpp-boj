#include <iostream>
#include <algorithm>
#define MAX 500001
using namespace std;

int list[MAX], tree[MAX * 4], lazy[MAX * 4];
int N, M;

int init(int node, int s, int e) {
	if (s == e) return tree[node] = list[s];

	int m = (s + e) / 2;
	return tree[node] = init(node * 2, s, m) ^ init(node * 2 + 1, m + 1, e);
}

void updateLazy(int node, int s, int e) {
	if (!lazy[node]) return;
	tree[node] ^= lazy[node];
	if (s != e) {
		lazy[node * 2] ^= lazy[node];
		lazy[node * 2 + 1] ^= lazy[node];
	}
	lazy[node] = 0;
}

void update(int node, int s, int e, int l, int r, int diff) {
	updateLazy(node, s, e);
	if (l <= s && e <= r) {
		tree[node] ^= diff;
		if (s != e) {
			lazy[node * 2] ^= diff;
			lazy[node * 2 + 1] ^= diff;
		}
		return;
	}
	if (s > r || e < l) return;

	int m = (s + e) / 2;
	update(node * 2, s, m, l, r, diff);
	update(node * 2 + 1, m + 1, e, l, r, diff);
	tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
}

int query(int node, int s, int e, int idx) {
	updateLazy(node, s, e);
	if (s == e) return tree[node];

	int m = (s + e) / 2;
	if (s <= idx && idx <= m) return query(node * 2, s, m, idx);
	else return query(node * 2 + 1, m + 1, e, idx);
}

void func() {
	int type, a, b, c;
	cin >> M;
	while (M--) {
		cin >> type;
		if (type == 1) {
			cin >> a >> b >> c;
			update(1, 0, N - 1, a, b, c);
		}
		else {
			cin >> a;
			cout << query(1, 0, N - 1, a) << '\n';
		}
	}
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
	init(1, 0, N - 1);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
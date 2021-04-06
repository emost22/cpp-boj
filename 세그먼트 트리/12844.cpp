#include <iostream>
#include <algorithm>
using namespace std;

int list[500001], tree[2000001], lazy[2000001];
int N, M;

int init(int node, int s, int e) {
	if (s == e) {
		return tree[node] = list[s];
	}

	int m = (s + e) / 2;
	return tree[node] = init(node * 2, s, m) ^ init(node * 2 + 1, m + 1, e);
}

void updateLazy(int node, int s, int e) {
	if (!lazy[node]) return;

	if ((e - s + 1) % 2) tree[node] ^= lazy[node];
	if (s != e) {
		lazy[node * 2] ^= lazy[node];
		lazy[node * 2 + 1] ^= lazy[node];
	}
	lazy[node] = 0;
}

void update(int node, int s, int e, int l, int r, int diff) {
	updateLazy(node, s, e);
	if (e<l || s>r) return;
	if (l <= s && e <= r) {
		if ((e - s + 1) % 2) tree[node] ^= diff;
		if (s == e) return;

		lazy[node * 2] ^= diff;
		lazy[node * 2 + 1] ^= diff;
		return;
	}

	int m = (s + e) / 2;
	update(node * 2, s, m, l, r, diff);
	update(node * 2 + 1, m + 1, e, l, r, diff);

	tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
}

int query(int node, int s, int e, int l, int r) {
	updateLazy(node, s, e);
	if (e<l || s>r) return 0;
	if (l <= s && e <= r) return tree[node];

	int m = (s + e) / 2;
	return query(node * 2, s, m, l, r) ^ query(node * 2 + 1, m + 1, e, l, r);
}

void func() {
	int type, k, x, y;
	cin >> M;
	while (M--) {
		cin >> type;
		if (type == 1) {
			cin >> x >> y >> k;
			update(1, 1, N, min(x + 1, y + 1), max(x + 1, y + 1), k);
		}
		else {
			cin >> x >> y;
			cout << query(1, 1, N, min(x + 1, y + 1), max(x + 1, y + 1)) << '\n';
		}
	}
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> list[i];
	}
	init(1, 1, N);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
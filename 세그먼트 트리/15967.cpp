#include <iostream>
#include <algorithm>
#define MAX 1000001
using namespace std;
typedef long long ll;

ll tree[MAX * 4], lazy[MAX * 4], list[MAX];
int N, Q1, Q2;

ll init(int node, int s, int e) {
	if (s == e) {
		return tree[node] = list[s];
	}

	int m = (s + e) / 2;
	return tree[node] = init(node * 2, s, m) + init(node * 2 + 1, m + 1, e);
}

void lazyUpdate(int node, int s, int e) {
	if (!lazy[node]) return;
	tree[node] += ((1LL * e - s + 1) * lazy[node]);
	if (s != e) {
		lazy[node * 2] += lazy[node];
		lazy[node * 2 + 1] += lazy[node];
	}
	lazy[node] = 0;
}

void update(int node, int s, int e, int l, int r, int diff) {
	lazyUpdate(node, s, e);
	if (s > r || l > e) return;
	if (l <= s && e <= r) {
		lazy[node] += diff;
		lazyUpdate(node, s, e);
		return;
	}

	int m = (s + e) / 2;
	update(node * 2, s, m, l, r, diff);
	update(node * 2 + 1, m + 1, e, l, r, diff);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll query(int node, int s, int e, int l, int r) {
	lazyUpdate(node, s, e);
	if (s > r || l > e) return 0;
	if (l <= s && e <= r) return tree[node];

	int m = (s + e) / 2;
	return query(node * 2, s, m, l, r) + query(node * 2 + 1, m + 1, e, l, r);
}

void func() {
	int type, x, y, k;
	int M = Q1 + Q2;
	while (M--) {
		cin >> type;
		if (type == 1) {
			cin >> x >> y;
			cout << query(1, 1, N, x, y) << '\n';
		}
		else {
			cin >> x >> y >> k;
			update(1, 1, N, x, y, k);
		}
	}
}

void input() {
	cin >> N >> Q1 >> Q2;
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
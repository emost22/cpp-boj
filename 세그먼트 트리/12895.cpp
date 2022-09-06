#include <iostream>
#define MAX 100001
using namespace std;

int tree[MAX * 4], lazy[MAX * 4];
int N, M, K;

void init(int node, int s, int e) {
	if (s == e) {
		tree[node] = 1;
		return;
	}

	int m = (s + e) / 2;
	init(node * 2, s, m);
	init(node * 2 + 1, m + 1, e);
	tree[node] = tree[node * 2] | tree[node * 2 + 1];
}

void lazyUpdate(int node, int s, int e) {
	if (!lazy[node]) return;

	tree[node] = lazy[node];
	if (s != e) {
		lazy[node * 2] = lazy[node];
		lazy[node * 2 + 1] = lazy[node];
	}
	lazy[node] = 0;
}

void update(int node, int s, int e, int l, int r, int k) {
	lazyUpdate(node, s, e);
	if (s > r || l > e) return;
	if (l <= s && e <= r) {
		lazy[node] = (1 << k);
		lazyUpdate(node, s, e);
		return;
	}

	int m = (s + e) / 2;
	update(node * 2, s, m, l, r, k);
	update(node * 2 + 1, m + 1, e, l, r, k);
	tree[node] = tree[node * 2] | tree[node * 2 + 1];
}

int query(int node, int s, int e, int l, int r) {
	lazyUpdate(node, s, e);
	if (s > r || l > e) return 0;
	if (l <= s && e <= r) return tree[node];

	int m = (s + e) / 2;
	return query(node * 2, s, m, l, r) | query(node * 2 + 1, m + 1, e, l, r);
}

void func() {
	char type;
	int l, r, k;
	while (K--) {
		cin >> type;
		if (type == 'C') {
			cin >> l >> r >> k;
			if (l > r) swap(l, r);
			update(1, 1, N, l, r, k - 1);
		}
		else {
			cin >> l >> r;
			if (l > r) swap(l, r);
			int ret = query(1, 1, N, l, r);
			int ans = 0;
			while (ret) {
				ans += (ret & 1);
				ret >>= 1;
			}
			cout << ans << '\n';
		}
	}
}

void input() {
	cin >> N >> M >> K;
	init(1, 1, N);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
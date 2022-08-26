#include <iostream>
#define MAX 100001
#define MOD 1000000007
using namespace std;
typedef long long ll;

typedef struct Point {
	ll x, lazy[2] = { 1,0 };
}Point;

Point tree[MAX * 4];
ll list[MAX];
int N, M;

ll init(int node, int s, int e) {
	if (s == e) {
		return tree[node].x = list[s];
	}

	int m = (s + e) / 2;
	return tree[node].x = (init(node * 2, s, m) + init(node * 2 + 1, m + 1, e)) % MOD;
}

void lazyUpdate(int node, int s, int e) {
	if (tree[node].lazy[0] != 1) {
		tree[node].x = (tree[node].x * tree[node].lazy[0]) % MOD;
		if (s != e) {
			tree[node * 2].lazy[0] = (tree[node * 2].lazy[0] * tree[node].lazy[0]) % MOD;
			tree[node * 2].lazy[1] = (tree[node * 2].lazy[1] * tree[node].lazy[0]) % MOD;

			tree[node * 2 + 1].lazy[0] = (tree[node * 2 + 1].lazy[0] * tree[node].lazy[0]) % MOD;
			tree[node * 2 + 1].lazy[1] = (tree[node * 2 + 1].lazy[1] * tree[node].lazy[0]) % MOD;
		}
		tree[node].lazy[0] = 1;
	}
	if (tree[node].lazy[1]) {
		tree[node].x = (tree[node].x + tree[node].lazy[1] * (1LL * e - s + 1)) % MOD;
		if (s != e) {
			tree[node * 2].lazy[1] = (tree[node * 2].lazy[1] + tree[node].lazy[1]) % MOD;
			tree[node * 2 + 1].lazy[1] = (tree[node * 2 + 1].lazy[1] + tree[node].lazy[1]) % MOD;
		}
		tree[node].lazy[1] = 0;
	}
}

void addUpdate(int node, int s, int e, int l, int r, ll diff) {
	lazyUpdate(node, s, e);
	if (s > r || l > e) return;
	if (l <= s && e <= r) {
		tree[node].lazy[0] = 1;
		tree[node].lazy[1] = diff;
		lazyUpdate(node, s, e);
		return;
	}

	int m = (s + e) / 2;
	addUpdate(node * 2, s, m, l, r, diff);
	addUpdate(node * 2 + 1, m + 1, e, l, r, diff);
	tree[node].x = (tree[node * 2].x + tree[node * 2 + 1].x) % MOD;
}

void mulUpdate(int node, int s, int e, int l, int r, ll diff) {
	lazyUpdate(node, s, e);
	if (s > r || l > e) return;
	if (l <= s && e <= r) {
		tree[node].lazy[0] = diff;
		tree[node].lazy[1] = 0;
		lazyUpdate(node, s, e);
		return;
	}

	int m = (s + e) / 2;
	mulUpdate(node * 2, s, m, l, r, diff);
	mulUpdate(node * 2 + 1, m + 1, e, l, r, diff);
	tree[node].x = (tree[node * 2].x + tree[node * 2 + 1].x) % MOD;
}

void update(int node, int s, int e, int l, int r, ll diff) {
	lazyUpdate(node, s, e);
	if (s > r || l > e) return;
	if (l <= s && e <= r) {
		tree[node].lazy[0] = 0;
		tree[node].lazy[1] = diff;
		lazyUpdate(node, s, e);
		return;
	}

	int m = (s + e) / 2;
	update(node * 2, s, m, l, r, diff);
	update(node * 2 + 1, m + 1, e, l, r, diff);
	tree[node].x = (tree[node * 2].x + tree[node * 2 + 1].x) % MOD;
}

ll query(int node, int s, int e, int l, int r) {
	lazyUpdate(node, s, e);
	if (s > r || l > e) return 0;
	if (l <= s && e <= r) return tree[node].x;

	int m = (s + e) / 2;
	return (query(node * 2, s, m, l, r) + query(node * 2 + 1, m + 1, e, l, r)) % MOD;
}

void func() {
	cin >> M;
	while (M--) {
		int type, x, y;
		ll v;
		cin >> type;
		if (type == 1) {
			cin >> x >> y >> v;
			addUpdate(1, 1, N, x, y, v);
		}
		else if (type == 2) {
			cin >> x >> y >> v;
			mulUpdate(1, 1, N, x, y, v);
		}
		else if (type == 3) {
			cin >> x >> y >> v;
			update(1, 1, N, x, y, v);
		}
		else {
			cin >> x >> y;
			cout << query(1, 1, N, x, y) << '\n';
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
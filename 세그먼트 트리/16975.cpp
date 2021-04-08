#include <iostream>
using namespace std;
typedef long long ll;

ll list[100001], tree[400001], lazy[400001];
int N, M;

void init(int node, int s, int e) {
	if (s == e) {
		tree[node] = list[s];
		return;
	}

	int m = (s + e) / 2;
	init(node * 2, s, m);
	init(node * 2 + 1, m + 1, e);
}

void updateLazy(int node, int s, int e) {
	if (!lazy[node]) return;
	if (s == e) tree[node] += lazy[node];
	else {
		lazy[node * 2] += lazy[node];
		lazy[node * 2 + 1] += lazy[node];
	}
	lazy[node] = 0;
}

void update(int node, int s, int e, int l, int r, ll diff) {
	updateLazy(node, s, e);
	if (s > r || l > e) return;
	if (l <= s && e <= r) {
		if (s == e) tree[node] += diff;
		else {
			lazy[node * 2] += diff;
			lazy[node * 2 + 1] += diff;
		}
		return;
	}

	int m = (s + e) / 2;
	update(node * 2, s, m, l, r, diff);
	update(node * 2 + 1, m + 1, e, l, r, diff);
}

void query(int node, int s, int e, int idx) {
	updateLazy(node, s, e);
	if (s > idx || idx > e) return;
	if (s == e) {
		cout << tree[node] << '\n';
		return;
	}

	int m = (s + e) / 2;
	query(node * 2, s, m, idx);
	query(node * 2 + 1, m + 1, e, idx);
}

void func() {
	int type, x, y;
	ll k;
	cin >> M;
	while (M--) {
		cin >> type;
		if (type == 1) {
			cin >> x >> y >> k;
			update(1, 1, N, x, y, k);
		}
		else {
			cin >> x;
			query(1, 1, N, x);
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
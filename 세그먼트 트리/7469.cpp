#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1000000000
using namespace std;

typedef struct query {
	int l;
	int r;
	int x;
}Q;

int N, M;
vector<int> tree[400004];
Q q[5000];

void update(int node, int s, int e, int idx, int x) {
	if (idx < s || idx > e) return;
	tree[node].push_back(x);
	if (s == e) return;
	
	int m = (s + e) / 2;

	update(node * 2, s, m, idx, x);
	update(node * 2 + 1, m + 1, e, idx, x);
}

void treesort(int node, int s, int e) {
	sort(tree[node].begin(), tree[node].end());
	if (s == e) return;

	int m = (s + e) / 2;
	treesort(node * 2, s, m);
	treesort(node * 2 + 1, m + 1, e);
}

int query(int node, int s, int e, int l, int r, int x) {
	if (s > r || l > e) return 0;
	if (l <= s && e <= r) return upper_bound(tree[node].begin(), tree[node].end(), x) - tree[node].begin();
	int m = (s + e) / 2;
	return query(node * 2, s, m, l, r, x) + query(node * 2 + 1, m + 1, e, l, r, x);
}

void func() {
	for (int i = 0; i < M; i++) {
		int l = -INF;
		int r = INF;
		while (l <= r) {
			int m = (l + r) / 2;
			if (query(1, 1, N, q[i].l, q[i].r, m) < q[i].x) l = m + 1;
			else r = m - 1;
		}

		cout << l << '\n';
	}
}

void input() {
	int x;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> x;
		update(1, 1, N, i, x);
	}
	treesort(1, 1, N);

	for (int i = 0; i < M; i++) {
		cin >> q[i].l >> q[i].r >> q[i].x;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
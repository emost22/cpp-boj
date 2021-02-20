#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> tree[400004];
int N, M;

void update(int node, int s, int e, int idx, int diff) {
	if (s > idx || e < idx) return;
	tree[node].push_back(diff);
	if (s == e) return;

	int m = (s + e) / 2;
	update(node * 2, s, m, idx, diff);
	update(node * 2 + 1, m + 1, e, idx, diff);
}

int query(int node, int s, int e, int l, int r, int x) {
	if (s > r || e < l) return 0;
	if (l <= s && e <= r) return tree[node].end() - upper_bound(tree[node].begin(), tree[node].end(), x);

	int m = (s + e) / 2;
	return query(node * 2, s, m, l, r, x) + query(node * 2 + 1, m + 1, e, l, r, x);
}

void func() {
	int i, j, k;
	cin >> M;
	while (M--) {
		cin >> i >> j >> k;
		cout << query(1, 1, N, i, j, k) << '\n';
	}
}

void input() {
	int x;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> x;
		update(1, 1, N, i, x);
	}

	for (int i = 1; i <= N * 4; i++) sort(tree[i].begin(), tree[i].end());
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
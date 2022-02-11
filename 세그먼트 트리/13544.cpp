#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 100001
using namespace std;

vector<int> tree[MAX * 4];
int N, M;

void update(int node, int s, int e, int idx, int k) {
	if (s > idx || e < idx) return;
	tree[node].push_back(k);
	if (s == e) return;

	int m = (s + e) >> 1;
	update(node * 2, s, m, idx, k);
	update(node * 2 + 1, m + 1, e, idx, k);
}

int query(int node, int s, int e, int l, int r, int k) {
	if (s > r || e < l) return 0;
	if (l <= s && e <= r) return tree[node].end() - upper_bound(tree[node].begin(), tree[node].end(), k);
	int m = (s + e) >> 1;
	return query(node * 2, s, m, l, r, k) + query(node * 2 + 1, m + 1, e, l, r, k);
}

void func() {
	int a, b, c;
	int ans = 0;
	cin >> M;
	while (M--) {
		cin >> a >> b >> c;
		a ^= ans;
		b ^= ans;
		c ^= ans;

		ans = query(1, 1, N, a, b, c);
		cout << ans << '\n';
	}
}

void input() {
	int x;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> x;
		update(1, 1, N, i, x);
	}

	for (int i = 1; i <= N * 4; i++) {
		sort(tree[i].begin(), tree[i].end());
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
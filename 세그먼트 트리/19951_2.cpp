#include <iostream>
#include <algorithm>
#define MAX 100002
using namespace std;

int tree[MAX * 4], list[MAX];
int N, M;

void update(int node, int s, int e, int l, int r, int diff) {
	if (s > r || e < l) return;
	if (l <= s && e <= r) {
		tree[node] += diff;
		return;
	}

	int m = (s + e) / 2;
	update(node * 2, s, m, l, r, diff);
	update(node * 2 + 1, m + 1, e, l, r, diff);
}

int query(int node, int s, int e, int idx, int ans) {
	if (s > idx || idx > e) return 0;
	ans += tree[node];
	if (s == e) return ans;

	int m = (s + e) / 2;
	return query(node * 2, s, m, idx, ans) + query(node * 2 + 1, m + 1, e, idx, ans);
}

void func() {
	int l, r, x;
	while (M--) {
		cin >> l >> r >> x;
		update(1, 1, N, l, r, x);
	}

	for (int i = 1; i <= N; i++) {
		cout << list[i] + query(1, 1, N, i, 0) << ' ';
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
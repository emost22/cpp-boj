#include <iostream>
#include <algorithm>
#define INF 2147483647
using namespace std;

int tree[400004];
int N, M;

int update(int node, int s, int e, int idx, int diff) {
	if (idx < s || idx > e) return tree[node];
	if (s == e) return tree[node] = diff;

	int m = (s + e) / 2;
	return tree[node] = min(update(node * 2, s, m, idx, diff), update(node * 2 + 1, m + 1, e, idx, diff));
}

int query(int node, int s, int e, int l, int r) {
	if (l <= s && e <= r) return tree[node];
	if (l > e || r < s) return INF;

	int m = (s + e) / 2;
	return min(query(node * 2, s, m, l, r), query(node * 2 + 1, m + 1, e, l, r));
}

void func() {
	int type, a, b;
	cin >> M;
	while (M--) {
		cin >> type >> a >> b;
		if (type == 1) {
			update(1, 1, N, a, b);
		}
		else {
			cout << query(1, 1, N, a, b) << '\n';
		}
	}
}

void input() {
	int x;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> x;
		update(1, 1, N, i, x);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
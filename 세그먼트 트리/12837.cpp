#include <iostream>
using namespace std;
typedef long long ll;

ll tree[4000001];
int N, M;

ll update(int node, int s, int e, int idx, ll diff) {
	if (s > idx || e < idx) return tree[node];
	if (s == e) {
		return tree[node] += diff;
	}

	int m = (s + e) / 2;
	return tree[node] = (update(node * 2, s, m, idx, diff) + update(node * 2 + 1, m + 1, e, idx, diff));
}

ll query(int node, int s, int e, int l, int r) {
	if (l > e || s > r) return 0;
	if (l <= s && e <= r) return tree[node];

	int m = (s + e) / 2;
	return query(node * 2, s, m, l, r) + query(node * 2 + 1, m + 1, e, l, r);
}

void input() {
	int type, x, y;
	cin >> N >> M;
	while (M--) {
		cin >> type >> x >> y;
		if (type == 1) {
			update(1, 1, N, x, y);
		}
		else {
			cout << query(1, 1, N, x, y) << '\n';
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}
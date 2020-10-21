#include <iostream>
using namespace std;
typedef long long ll;

ll list[1000001], tree[4000004];
int N, M;

int Max(int x, int y) {
	return x > y ? x : y;
}

int Min(int x, int y) {
	return x < y ? x : y;
}

void update(int node, int s, int e, int index, ll diff) {
	if (index < s || e < index) return;
	
	tree[node] += diff;
	if (s != e) {
		int m = (s + e) / 2;
		update(node * 2, s, m, index, diff);
		update(node * 2 + 1, m + 1, e, index, diff);
	}
}

ll findsum(int node, int s, int e, int l, int r) {
	if (e < l || r < s) return 0;
	if (l <= s && e <= r) return tree[node];

	if (s != e) {
		int m = (s + e) / 2;
		return findsum(node * 2, s, m, l, r) + findsum(node * 2 + 1, m + 1, e, l, r);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	ll a, b, c;
	cin >> N >> M;
	while (M--) {
		cin >> a >> b >> c;
		if (!a) {
			cout << findsum(1, 1, N, Min(b, c), Max(b, c)) << '\n';
		}
		else {
			update(1, 1, N, b, c - list[b]);
			list[b] = c;
		}
	}

	return 0;
}
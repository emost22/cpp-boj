#include <iostream>
using namespace std;
typedef long long ll;

ll list[100001], tree[400004];
int N, Q;

int Max(int x, int y) {
	return x > y ? x : y;
}

int Min(int x, int y) {
	return x < y ? x : y;
}

ll init(int node, int s, int e) {
	if (s == e) return tree[node] = list[s];

	int m = (s + e) / 2;
	return tree[node] = init(node * 2, s, m) + init(node * 2 + 1, m + 1, e);
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

ll sum(int node, int s, int e, int l, int r) {
	if (s > r || l > e) return 0;
	if (l <= s && e <= r) return tree[node];

	ll divsum = 0;
	if (s != e) {
		int m = (s + e) / 2;
		divsum = sum(node * 2, s, m, l, r) + sum(node * 2 + 1, m + 1, e, l, r);
	}

	return divsum;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	ll x, y, a, b;

	cin >> N >> Q;
	for (int i = 1; i <= N; i++) {
		cin >> list[i];
	}

	init(1, 1, N);

	while (Q--) {
		cin >> x >> y >> a >> b;
		cout << sum(1, 1, N, Min(x, y), Max(x, y)) << '\n';
		update(1, 1, N, a, b - list[a]);
		list[a] = b;
	}

	return 0;
}
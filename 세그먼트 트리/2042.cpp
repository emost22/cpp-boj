#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll list[1000001], tree[4000004];
int N, M, K;

ll init(int s, int e, int node) {
	if (s == e) {
		return tree[node] = list[s];
	}

	int m = (s + e) / 2;
	return tree[node] = init(s, m, node * 2) + init(m + 1, e, node * 2 + 1);
}

void update(int s, int e, int node, int idx, int diff) {
	if (idx < s || e < idx) return;

	tree[node] += diff;

	if (s != e) {
		int m = (s + e) / 2;
		update(s, m, node * 2, idx, diff);
		update(m + 1, e, node * 2 + 1, idx, diff);
	}
}

ll sum(int s, int e, int l, int r, int node) {
	if (s > r || e < l) return 0;
	if (l <= s && e <= r) return tree[node];

	int m = (s + e) / 2;
	return sum(s, m, l, r, node * 2) + sum(m + 1, e, l, r, node * 2 + 1);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int a, b, c;
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		cin >> list[i];
	}
	init(1, N, 1);

	for (int i = 0; i < M + K; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			update(1, N, 1, b, c - list[b]);
			list[b] = c;
		}
		else {
			cout << sum(1, N, min(b, c), max(b, c), 1) << '\n';
		}
	}

	return 0;
}
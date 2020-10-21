#include <iostream>
#define mod 1000000007
using namespace std;
typedef long long ll;

int N, M, K;
ll list[1000001], tree[4000004], ans = 1;

ll init(int node, int s, int e) {
	if (s == e) return tree[node] = list[s];

	int m = (s + e) / 2;

	return tree[node] = (init(node * 2, s, m)*init(node * 2 + 1, m + 1, e)) % mod;
}

void update(int node, int s, int e, int index, int diff) {
	if (s > index || index > e) return;
	if (s == e) tree[node] = diff % mod;
	else {
		int m = (s + e) / 2;
		update(node * 2, s, m, index, diff);
		update(node * 2 + 1, m + 1, e, index, diff);

		tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % mod;
	}
}

ll divmultiple(int node, int s, int e, int l, int r) {
	if (r < s || e < l) return 1;
	if (l <= s && e <= r) return tree[node];
	
	int m = (s + e) / 2;
	ll mul1 = divmultiple(node * 2, s, m, l, r);
	ll mul2 = divmultiple(node * 2 + 1, m + 1, e, l, r);
	return (mul1 * mul2) % mod;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		cin >> list[i];
	}

	init(1, 1, N);

	for (int j = 0; j < M + K; j++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			update(1, 1, N, b, c);
			list[b] = c;
		}
		else {
			ans = divmultiple(1, 1, N, b, c);
			cout << ans << '\n';
			ans = 1;
		}
	}

	return 0;
}
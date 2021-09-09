#include <iostream>
#define MAX 1000000
using namespace std;
typedef long long ll;

int tree[(MAX + 1) * 4];
int N;
ll ans;

void update(int node, int s, int e, int idx, int diff) {
	if (s > idx || idx > e) return;
	if (s == e) {
		tree[node] = diff;
		return;
	}

	int m = (s + e) / 2;
	update(node * 2, s, m, idx, diff);
	update(node * 2 + 1, m + 1, e, idx, diff);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int node, int s, int e, int l, int r) {
	if (l <= s && e <= r) return tree[node];
	if (l > e || s > r) return 0;

	int m = (s + e) / 2;
	return query(node * 2, s, m, l, r) + query(node * 2 + 1, m + 1, e, l, r);
}

void input() {
	int x;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> x;
		update(1, 1, N, x, 1);
		ans += (ll)query(1, 1, N, x + 1, N);
	}

	cout << ans << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}
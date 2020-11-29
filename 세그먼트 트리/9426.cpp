#include <iostream>
#define MAX 65535
using namespace std;
typedef long long ll;

int N, K;
int list[250001], tree[(MAX + 1) * 4];

void update(int node, int s, int e, int num, int diff) {
	if (num < s || num > e) return;

	tree[node] += diff;
	if (s == e) return;

	int m = (s + e) / 2;
	update(node * 2, s, m, num, diff);
	update(node * 2 + 1, m + 1, e, num, diff);
}

int query(int node, int s, int e, int k) {
	if (s == e) return s;

	int m = (s + e) / 2;
	if (tree[node * 2] >= k) return query(node * 2, s, m, k);
	else return query(node * 2 + 1, m + 1, e, k - tree[node * 2]);
}

void func() {
	ll ans = 0;
	int m = (K + 1) / 2;
	for (int i = 1; i <= K - 1; i++) {
		update(1, 0, MAX, list[i], 1);
	}

	for (int i = K; i <= N; i++) {
		update(1, 0, MAX, list[i], 1);
		ans += (ll)query(1, 0, MAX, m);
		update(1, 0, MAX, list[i - K + 1], -1);
	}

	cout << ans << '\n';
}

void input() {
	cin >> N >> K;
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
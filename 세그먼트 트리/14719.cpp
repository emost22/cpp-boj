#include <iostream>
#include <algorithm>
using namespace std;

int list[501], tree[2001];
int N, M;

int init(int node, int s, int e) {
	if (s == e) {
		return tree[node] = list[s];
	}

	int m = (s + e) / 2;
	return tree[node] = max(init(node * 2, s, m), init(node * 2 + 1, m + 1, e));
}

int query(int node, int s, int e, int l, int r) {
	if (l > e || s > r) return 0;
	if (l <= s && e <= r) return tree[node];

	int m = (s + e) / 2;
	return max(query(node * 2, s, m, l, r), query(node * 2 + 1, m + 1, e, l, r));
}

void func() {
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		int l = query(1, 1, N, 1, i);
		int r = query(1, 1, N, i + 1, N);

		int result = min(l, r);

		if (list[i] < result) {
			ans += result - list[i];
		}
	}

	cout << ans << '\n';
}

void input() {
	cin >> M >> N;
	for (int i = 1; i <= N; i++) {
		cin >> list[i];
	}
	init(1, 1, N);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
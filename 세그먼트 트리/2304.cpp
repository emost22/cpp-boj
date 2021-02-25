#include <iostream>
#include <algorithm>
using namespace std;

int tree[4004], list[1001];
int N, L, ans;

int init(int node, int s, int e) {
	if (s == e) return tree[node] = list[s];

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
	for (int i = 1; i <= L; i++) {
		int l = query(1, 1, L, 1, i);
		int r = query(1, 1, L, i, L);

		if (list[i] < l || list[i] < r) {
			list[i] = min(l, r);
		}

		ans += list[i];
	}

	cout << ans << '\n';
}

void input() {
	int l, h;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> l >> h;
		list[l] = h;
		L = max(L, l);
	}
	init(1, 1, L);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
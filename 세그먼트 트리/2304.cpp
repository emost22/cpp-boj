#include <iostream>
#include <algorithm>
using namespace std;

int N, L;
int list[1001], tree[4004];

int init(int node, int s, int e) {
	if (s == e) {
		return tree[node] = list[s];
	}
	int m = (s + e) / 2;
	return tree[node] = max(init(node * 2, s, m), init(node * 2 + 1, m + 1, e));
}

int findmax(int node, int s, int e, int l, int r) {
	if (l <= s && e <= r) return tree[node];
	if (s > r || l > e) return 0;

	int m = (s + e) / 2;
	return max(findmax(node * 2, s, m, l, r), findmax(node * 2 + 1, m + 1, e, l, r));
}

void func() {
	int ans = 0;
	for (int i = 1; i <= L; i++) {
		int l = findmax(1, 1, L, 1, i);
		int r = findmax(1, 1, L, i, L);

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
	for (int i = 1; i <= N; i++) {
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
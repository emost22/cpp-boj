#include <iostream>
#include <algorithm>
#define MAX 1000001
using namespace std;

int tree[MAX * 4];
int N, M;

int update(int node, int s, int e, int idx, int k) {
	if (s > idx || idx > e) return tree[node];
	if (s == e) return tree[node] = max(tree[node], k);

	int m = (s + e) >> 1;
	return tree[node] = max(update(node * 2, s, m, idx, k), update(node * 2 + 1, m + 1, e, idx, k));
}

int query(int node, int s, int e, int l, int r) {
	if (s > r || e < l) return 0;
	if (l <= s && e <= r) return tree[node];

	int m = (s + e) >> 1;
	return max(query(node * 2, s, m, l, r), query(node * 2 + 1, m + 1, e, l, r));
}

void func() {
	for (int i = M; i <= N - M + 1; i++) {
		cout << query(1, 1, N, i - (M - 1), i + (M - 1)) << ' ';
	}
	cout << '\n';
}

void input() {
	int k;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> k;

		update(1, 1, N, i, k);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
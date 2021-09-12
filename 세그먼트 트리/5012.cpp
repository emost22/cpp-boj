#include <iostream>
#include <cstring>
#define MAX 100001
using namespace std;

int list[MAX], tree[MAX * 4], leftList[MAX], rightList[MAX];
int N;

void update(int node, int s, int e, int idx, int diff) {
	if (idx < s || e < idx) return;
	if (s == e) {
		tree[node] += diff;
		return;
	}

	int m = (s + e) / 2;
	update(node * 2, s, m, idx, diff);
	update(node * 2 + 1, m + 1, e, idx, diff);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int node, int s, int e, int l, int r) {
	if (s > r || l > e) return 0;
	if (l <= s && e <= r) return tree[node];

	int m = (s + e) / 2;
	return query(node * 2, s, m, l, r) + query(node * 2 + 1, m + 1, e, l, r);
}

void func() {
	for (int i = 1; i <= N; i++) {
		leftList[i] = query(1, 1, N, list[i] + 1, N);
		update(1, 1, N, list[i], 1);
	}
	memset(tree, 0, sizeof(tree));

	for (int i = N; i >= 1; i--) {
		rightList[i] = query(1, 1, N, 1, list[i] - 1);
		update(1, 1, N, list[i], 1);
	}

	long long ans = 0;
	for (int i = 1; i <= N; i++) {
		ans += (long long)leftList[i] * (long long)rightList[i];
	}

	cout << ans << '\n';
}

void input() {
	cin >> N;
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
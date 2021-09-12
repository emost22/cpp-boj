#include <iostream>
#include <cstring>
#define MAX 100001
using namespace std;

int aList[MAX], bList[MAX], tree[MAX * 4];
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
	long long ans = 0;
	for (int i = 1; i <= N; i++) {
		ans += (long long) query(1, 1, N, bList[i] + 1, N);
		update(1, 1, N, bList[i], 1);
	}

	cout << ans << '\n';
	memset(tree, 0, sizeof(tree));
}

void input() {
	int x;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> x;
		aList[x] = i;
	}

	for (int i = 1; i <= N; i++) {
		cin >> x;
		bList[i] = aList[x];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
	}

	return 0;
}
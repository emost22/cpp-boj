#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;
typedef long long ll;

ll tree[MAX * 4], list[MAX], ans;
int N;

void init(int node, int s, int e) {
	if (s == e) {
		tree[node] = s;
		return;
	}
	
	int m = (s + e) / 2;
	init(node * 2, s, m);
	init(node * 2 + 1, m + 1, e);
	
	int l = tree[node * 2];
	int r = tree[node * 2 + 1];
	if (list[l] < list[r]) tree[node] = l;
	else tree[node] = r;

	return;
}

int query(int node, int s, int e, int l, int r) {
	if (l > e || s > r) return -1;
	if (l <= s && e <= r) return tree[node];

	int m = (s + e) / 2;
	int lIdx = query(node * 2, s, m, l, r);
	int rIdx = query(node * 2 + 1, m + 1, e, l, r);

	if (lIdx == -1) {
		return rIdx;
	}
	else if (rIdx == -1) {
		return lIdx;
	}
	else {
		return list[lIdx] < list[rIdx] ? lIdx : rIdx;
	}
}

void partition(int s, int e) {
	if (s > e) return;

	int idx = query(1, 1, N, s, e);
	ans = max(ans, list[idx] * (ll)(e - s + 1));
	partition(s, idx - 1);
	partition(idx + 1, e);
}

void func() {
	init(1, 1, N);
	partition(1, N);

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
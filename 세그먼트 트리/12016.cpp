#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

ll tree[MAX * 4], ans[MAX];
pii list[MAX];
int N;

ll update(int node, int s, int e, int idx, int x) {
	if (idx < s || e < idx) return tree[node];
	if (s == e) {
		return tree[node] = x;
	}

	int m = (s + e) >> 1;
	return tree[node] = update(node * 2, s, m, idx, x) + update(node * 2 + 1, m + 1, e, idx, x);
}

ll query(int node, int s, int e, int l, int r) {
	if (s > r || l > e) return 0;
	if (l <= s && e <= r) return tree[node];

	int m = (s + e) >> 1;
	return query(node * 2, s, m, l, r) + query(node * 2 + 1, m + 1, e, l, r);
}

void func() {
	ll t = 0;
	for (int i = 1; i <= N; i++) {
		int value = list[i].first;
		int idx = list[i].second;

		ans[idx] = query(1, 1, N, 1, idx) * value + query(1, 1, N, idx + 1, N) * (value - 1) + t;
		t += value;
		update(1, 1, N, idx, 0);
	}

	for (int i = 1; i <= N; i++) {
		cout << ans[i] << '\n';
	}
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> list[i].first;
		list[i].second = i;
		update(1, 1, N, i, 1);
	}
	sort(list + 1, list + 1 + N);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
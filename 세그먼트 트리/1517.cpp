#include <iostream>
#include <algorithm>
#define MAX 500001
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

pii list[MAX];
ll tree[MAX << 2];
int N;

void compress() {
	sort(list, list + N);
	int pre = 1e9 + 1;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (pre != list[i].first) cnt++;
		pre = list[i].first;
		list[i].first = cnt;
	}
	sort(list, list + N, [](pii a, pii b) {
		return a.second < b.second;
	});
}

ll update(int node, int l, int r, int x) {
	if (x < l || r < x) return tree[node];
	if (l == r) return ++tree[node];

	int m = (l + r) >> 1;
	return tree[node] = update(node << 1, l, m, x) + update((node << 1) + 1, m + 1, r, x);
}

ll query(int node, int l, int r, int s, int e) {
	if (s <= l && r <= e) return tree[node];
	if (l > e || s > r) return 0;

	int m = (l + r) >> 1;
	return query(node << 1, l, m, s, e) + query((node << 1) + 1, m + 1, r, s, e);
}

void func() {
	compress();

	ll ret = 0;
	for (int i = 0; i < N; i++) {
		ret += query(1, 1, N, list[i].first + 1, N);
		update(1, 1, N, list[i].first);
	}
	cout << ret << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i].first;
		list[i].second = i;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
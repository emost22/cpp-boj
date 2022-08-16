#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 75001
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

pii list[MAX];
int tree[MAX * 4];
int N;

void update(int node, int s, int e, int idx, int diff) {
	if (idx < s || idx > e) return;
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
	if (l > e || s > r) return 0;
	if (l <= s && e <= r) {
		return tree[node];
	}

	int m = (s + e) / 2;
	return query(node * 2, s, m, l, r) + query(node * 2 + 1, m + 1, e, l, r);
}

void init() {
	sort(list, list + N, [](pii a, pii b) {
		return a.second < b.second;
	});

	int pre = 1e9 + 1;
	int y = -1;
	for (int i = 0; i < N; i++) {
		if (pre != list[i].second) y++;
		pre = list[i].second;
		list[i].second = y;
	}

	sort(list, list + N, [](pii a, pii b) {
		if (a.first != b.first) return a.first < b.first;
		else return a.second > b.second;
	});
}

void func() {
	init();

	ll ans = 0;
	for (int i = 0; i < N; i++) {
		ans += (ll)query(1, 0, N - 1, list[i].second, N - 1);
		update(1, 0, N - 1, list[i].second, 1);
	}

	cout << ans << '\n';
	memset(tree, 0, sizeof(tree));
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i].first >> list[i].second;
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
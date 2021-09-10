#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 500000
using namespace std;

vector<int> graph[MAX + 1];
int s[MAX + 1], e[MAX + 1], list[MAX + 1], tree[(MAX + 1) * 4], lazy[(MAX + 1) * 4];
int N, M, cnt;

void dfs(int v) {
	s[v] = ++cnt;
	for (int i = 0; i < graph[v].size(); i++) {
		int next = graph[v][i];
		if (s[next]) continue;

		dfs(next);
	}

	e[v] = cnt;
}

void updateLazy(int node, int s, int e) {
	if (!lazy[node]) return;

	tree[node] += (lazy[node] * (e - s + 1));
	if (s == e) {
		lazy[node] = 0;
		return;
	}
	lazy[node * 2] += lazy[node];
	lazy[node * 2 + 1] += lazy[node];
	lazy[node] = 0;
}

void update(int node, int s, int e, int l, int r, int diff) {
	updateLazy(node, s, e);
	if (s > r || e < l) return;
	if (l <= s && e <= r) {
		tree[node] += (diff * (e - s + 1));
		if (s == e) return;
		lazy[node * 2] += diff;
		lazy[node * 2 + 1] += diff;
		return;
	}

	int m = (s + e) / 2;
	update(node * 2, s, m, l, r, diff);
	update(node * 2 + 1, m + 1, e, l, r, diff);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int node, int s, int e, int idx) {
	updateLazy(node, s, e);
	if (idx < s || e < idx) return 0;
	if (s == e) return tree[node];

	int m = (s + e) / 2;
	return query(node * 2, s, m, idx) + query(node * 2 + 1, m + 1, e, idx);
}

void func() {
	char ch;
	int x, y;
	while (M--) {
		cin >> ch;
		if (ch == 'p') {
			cin >> x >> y;
			if (s[x] == e[x]) continue;
			update(1, 1, N, s[x] + 1, e[x], y);
		}
		else {
			cin >> x;
			cout << query(1, 1, N, s[x]) << '\n';
		}
	}
}

void input() {
	int n;
	cin >> N >> M >> list[1];
	for (int i = 2; i <= N; i++) {
		cin >> list[i] >> n;
		graph[n].push_back(i);
	}
	dfs(1);
	for (int i = 1; i <= N; i++) {
		update(1, 1, N, s[i], s[i], list[i]);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
#include <iostream>
#include <vector>
#define MAX 100001
using namespace std;

vector<int> list[MAX];
int tree[MAX * 4], lazy[MAX * 4], leftIdx[MAX], rightIdx[MAX];
int N, M, cnt;

void dfs(int v) {
	leftIdx[v] = ++cnt;
	for (auto next : list[v]) {
		dfs(next);
	}
	rightIdx[v] = cnt;
}

void lazyUpdate(int node, int s, int e) {
	if (!lazy[node]) return;
	tree[node] += lazy[node];
	if (s != e) {
		lazy[node * 2] += lazy[node];
		lazy[node * 2 + 1] += lazy[node];
	}
	lazy[node] = 0;
}

void update(int node, int s, int e, int l, int r, int diff) {
	lazyUpdate(node, s, e);
	if (l > e || s > r) return;
	if (l <= s && e <= r) {
		lazy[node] += diff;
		lazyUpdate(node, s, e);
		return;
	}

	int m = (s + e) / 2;
	update(node * 2, s, m, l, r, diff);
	update(node * 2 + 1, m + 1, e, l, r, diff);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int node, int s, int e, int idx) {
	lazyUpdate(node, s, e);
	if (idx < s || idx > e) return 0;
	if (s == e) return tree[node];

	int m = (s + e) / 2;
	return query(node * 2, s, m, idx) + query(node * 2 + 1, m + 1, e, idx);
}

void func() {
	dfs(1);

	int type, x, w;
	while (M--) {
		cin >> type;
		if (type == 1) {
			cin >> x >> w;
			update(1, 1, N, leftIdx[x], rightIdx[x], w);
		}
		else {
			cin >> x;
			cout << query(1, 1, N, leftIdx[x]) << '\n';
		}
	}
}

void input() {
	int x;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> x;
		if (x == -1) continue;
		list[x].push_back(i);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
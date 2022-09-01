#include <iostream>
#include <vector>
#define MAX 100001
using namespace std;

vector<int> list[MAX];
int tree1[MAX * 4], tree2[MAX * 4], lazy[MAX * 4], leftIdx[MAX], rightIdx[MAX];
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

	tree1[node] += lazy[node];
	if (s != e) {
		lazy[node * 2] += lazy[node];
		lazy[node * 2 + 1] += lazy[node];
	}
	lazy[node] = 0;
}

void update1(int node, int s, int e, int l, int r, int diff) {
	lazyUpdate(node, s, e);
	if (s > r || l > e) return;
	if (l <= s && e <= r) {
		lazy[node] += diff;
		lazyUpdate(node, s, e);
		return;
	}

	int m = (s + e) / 2;
	update1(node * 2, s, m, l, r, diff);
	update1(node * 2 + 1, m + 1, e, l, r, diff);
	tree1[node] = tree1[node * 2] + tree1[node * 2 + 1];
}

void update2(int node, int s, int e, int idx, int diff) {
	if (s > idx || idx > e) return;
	if (s == e) {
		tree2[node] += diff;
		return;
	}

	int m = (s + e) / 2;
	update2(node * 2, s, m, idx, diff);
	update2(node * 2 + 1, m + 1, e, idx, diff);
	tree2[node] = tree2[node * 2] + tree2[node * 2 + 1];
}

int query(int *tree, int node, int s, int e, int l, int r) {
	lazyUpdate(node, s, e);
	if (s > r || l > e) return 0;
	if (l <= s && e <= r) return tree[node];

	int m = (s + e) / 2;
	return query(tree, node * 2, s, m, l, r) + query(tree, node * 2 + 1, m + 1, e, l, r);
}

void func() {
	dfs(1);

	int type, x, w;
	bool flag = true;
	while (M--) {
		cin >> type;
		if (type == 1) {
			cin >> x >> w;
			if (flag) {
				update1(1, 1, N, leftIdx[x], rightIdx[x], w);
			}
			else {
				update2(1, 1, N, leftIdx[x], w);
			}
		}
		else if (type == 2) {
			cin >> x;
			cout << query(tree1, 1, 1, N, leftIdx[x], leftIdx[x]) + query(tree2, 1, 1, N, leftIdx[x], rightIdx[x]) << '\n';
		}
		else {
			flag = !flag;
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
#include <iostream>
#include <vector>
#define MAX 100001
using namespace std;

vector<int> list[MAX];
int tree[MAX * 4], leftIdx[MAX], rightIdx[MAX];
int N, M, cnt;

void dfs(int v) {
	leftIdx[v] = ++cnt;
	for (auto next : list[v]) {
		dfs(next);
	}
	rightIdx[v] = cnt;
}

void update(int node, int s, int e, int idx, int diff) {
	if (s > idx || idx > e) return;
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
	dfs(1);

	int type, x, w;
	while (M--) {
		cin >> type;
		if (type == 1) {
			cin >> x >> w;
			update(1, 1, N, leftIdx[x], w);
		}
		else {
			cin >> x;
			cout << query(1, 1, N, leftIdx[x], rightIdx[x]) << '\n';
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
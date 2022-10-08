#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;

typedef struct Node {
	int l, r, max, sum;
}Node;

Node tree[MAX * 4];
int N, M, U, V;

void update(int node, int s, int e, int idx, int k) {
	if (s > idx || idx > e) return;
	if (s == e) {
		tree[node] = { k, k, k, k };
		return;
	}

	int m = (s + e) >> 1;
	update(node * 2, s, m, idx, k);
	update(node * 2 + 1, m + 1, e, idx, k);
	tree[node] = { max(tree[node * 2].l, tree[node * 2].sum + tree[node * 2 + 1].l), max(tree[node * 2 + 1].r, tree[node * 2 + 1].sum + tree[node * 2].r), max(max(tree[node * 2].max, tree[node * 2 + 1].max), tree[node * 2].r + tree[node * 2 + 1].l), tree[node * 2].sum + tree[node * 2 + 1].sum };
}

Node query(int node, int s, int e, int l, int r) {
	if (s > r || l > e) return { (int)-1e9, (int)-1e9, (int)-1e9, 0 };
	if (l <= s && e <= r) return tree[node];

	int m = (s + e) >> 1;
	Node leftNode = query(node * 2, s, m, l, r);
	Node rightNode = query(node * 2 + 1, m + 1, e, l, r);
	return { max(leftNode.l, leftNode.sum + rightNode.l), max(rightNode.r, rightNode.sum + leftNode.r), max(max(leftNode.max, rightNode.max), leftNode.r + rightNode.l), leftNode.sum + rightNode.sum };
}

void func() {
	int type;
	while (M--) {
		cin >> type;
		if (type) {
			int idx, x;
			cin >> idx >> x;
			update(1, 1, N, idx, x * U + V);
		}
		else {
			int l, r;
			cin >> l >> r;
			cout << query(1, 1, N, l, r).max - V << '\n';
		}
	}
}

void input() {
	int x;
	cin >> N >> M >> U >> V;
	for (int i = 1; i <= N; i++) {
		cin >> x;
		update(1, 1, N, i, x * U + V);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;

typedef struct Node {
	int l;
	int r;
	int max;
	int sum;
}Node;

Node tree[MAX * 4];
int list[MAX];
int N, M, U, V;

void init(int node, int s, int e) {
	if (s == e) {
		tree[node] = { U * list[s] + V, U * list[s] + V, U * list[s] + V, U * list[s] + V };
		return;
	}

	int m = (s + e) / 2;
	init(node * 2, s, m);
	init(node * 2 + 1, m + 1, e);
	tree[node] = { max(tree[node * 2].l, tree[node * 2].sum + tree[node * 2 + 1].l), max(tree[node * 2 + 1].r, tree[node * 2 + 1].sum + tree[node * 2].r), max(max(tree[node * 2].max, tree[node * 2 + 1].max), tree[node * 2].r + tree[node * 2 + 1].l), tree[node * 2].sum + tree[node * 2 + 1].sum };
}

void update(int node, int s, int e, int idx, int diff) {
	if (idx < s || idx > e) return;
	if (s == e) {
		tree[node] = { diff, diff, diff, diff };
		return;
	}

	int m = (s + e) / 2;
	update(node * 2, s, m, idx, diff);
	update(node * 2 + 1, m + 1, e, idx, diff);
	tree[node] = { max(tree[node * 2].l, tree[node * 2].sum + tree[node * 2 + 1].l), max(tree[node * 2 + 1].r, tree[node * 2 + 1].sum + tree[node * 2].r), max(max(tree[node * 2].max, tree[node * 2 + 1].max), tree[node * 2].r + tree[node * 2 + 1].l), tree[node * 2].sum + tree[node * 2 + 1].sum };
}

Node query(int node, int s, int e, int l, int r) {
	if (l > e || s > r) return { (int)-1e9, (int)-1e9, (int)-1e9, 0 };
	if (l <= s && e <= r) return tree[node];

	int m = (s + e) / 2;
	Node leftNode = query(node * 2, s, m, l, r);
	Node rightNode = query(node * 2 + 1, m + 1, e, l, r);
	return { max(leftNode.l,leftNode.sum + rightNode.l), max(rightNode.r, rightNode.sum + leftNode.r), max(max(leftNode.max, rightNode.max), leftNode.r + rightNode.l), leftNode.sum + rightNode.sum };
}

void func() {
	int type, x, y;
	while (M--) {
		cin >> type >> x >> y;
		if (!type) {
			cout << query(1, 1, N, x, y).max - V << '\n';
		}
		else {
			list[x] = y;
			update(1, 1, N, x, y * U + V);
		}
	}
}

void input() {
	cin >> N >> M >> U >> V;
	for (int i = 1; i <= N; i++) {
		cin >> list[i];
	}
	init(1, 1, N);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
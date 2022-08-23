#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;
typedef long long ll;

typedef struct Node {
	ll l;
	ll r;
	ll max;
	ll sum;
}Node;

Node tree[MAX * 4];
int list[MAX];
int N, M;

void init(int node, int s, int e) {
	if (s == e) {
		tree[node] = { list[s], list[s], list[s], list[s] };
		return;
	}

	int m = (s + e) / 2;
	init(node * 2, s, m);
	init(node * 2 + 1, m + 1, e);
	tree[node] = { max(tree[node * 2].l, tree[node * 2].sum + tree[node * 2 + 1].l), max(tree[node * 2 + 1].r, tree[node * 2 + 1].sum + tree[node * 2].r), max(max(tree[node * 2].max, tree[node * 2 + 1].max), tree[node * 2].r + tree[node * 2 + 1].l), tree[node * 2].sum + tree[node * 2 + 1].sum };
}

Node query(int node, int s, int e, int l, int r) {
	if (s > r || l > e) return { (int)-1e9, (int)-1e9, (int)-1e9, 0 };
	if (l <= s && e <= r) return tree[node];

	int m = (s + e) / 2;
	Node leftNode = query(node * 2, s, m, l, r);
	Node rightNode = query(node * 2 + 1, m + 1, e, l, r);
	return { max(leftNode.l, leftNode.sum + rightNode.l), max(rightNode.r, rightNode.sum + leftNode.r), max(max(leftNode.max,rightNode.max),leftNode.r + rightNode.l), leftNode.sum + rightNode.sum };
}

void func() {
	int x1, y1, x2, y2;
	cin >> M;
	while (M--) {
		cin >> x1 >> y1 >> x2 >> y2;

		if (y1 >= x2) {
			Node leftNode = query(1, 1, N, x1, x2 - 1);
			Node middleNode = query(1, 1, N, x2, y1);
			Node rightNode = query(1, 1, N, y1 + 1, y2);

			cout << max({ leftNode.r + middleNode.l, middleNode.r + rightNode.l, leftNode.r + middleNode.sum + rightNode.l, middleNode.max }) << '\n';
		}
		else {
			cout << query(1, 1, N, x1, y1).r + query(1, 1, N, y1 + 1, x2 - 1).sum + query(1, 1, N, x2, y2).l << '\n';
		}
	}
}

void input() {
	cin >> N;
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
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
int N, M;

Node init(int node, int s, int e) {
	if (s == e) {
		return tree[node] = { list[s], list[s], list[s], list[s] };
	}

	int m = (s + e) / 2;
	Node leftNode = init(node * 2, s, m);
	Node rightNode = init(node * 2 + 1, m + 1, e);
	return tree[node] = { max(leftNode.l, leftNode.sum + rightNode.l), max(rightNode.r, leftNode.r + rightNode.sum), max(max(leftNode.max, rightNode.max), leftNode.r + rightNode.l), leftNode.sum + rightNode.sum };
}

Node query(int node, int s, int e, int l, int r) {
	if (s > r || l > e) return { (int)-1e9, (int)-1e9, (int)-1e9, 0 };
	if (l <= s && e <= r) return tree[node];

	int m = (s + e) / 2;
	Node leftNode = query(node * 2, s, m, l, r);
	Node rightNode = query(node * 2 + 1, m + 1, e, l, r);
	return { max(leftNode.l, leftNode.sum + rightNode.l), max(rightNode.r, leftNode.r + rightNode.sum), max(max(leftNode.max, rightNode.max), leftNode.r + rightNode.l), leftNode.sum + rightNode.sum };
}

void func() {
	int l, r;
	cin >> M;
	while (M--) {
		cin >> l >> r;
		cout << query(1, 1, N, l, r).max << '\n';
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
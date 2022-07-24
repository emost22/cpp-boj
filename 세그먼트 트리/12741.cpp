#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;

typedef struct Point {
	int l, r;
	bool isSorted;
}Point;

Point tree[MAX * 4];
int list[MAX];
int N, M;

Point query(int node, int s, int e, int l, int r) {
	if (l <= s && e <= r) return tree[node];
	if (l > e || s > r) return { -1,-1,false };
	
	int m = (s + e) / 2;
	Point lt = query(node * 2, s, m, l, r);
	Point rt = query(node * 2 + 1, m + 1, e, l, r);
	if (lt.l == -1) return rt;
	if (rt.l == -1) return lt;
	return { lt.l, rt.r, lt.isSorted && rt.isSorted && lt.r <= rt.l };
}

void update(int node, int s, int e, int idx, int diff) {
	if (s > idx || idx > e) return;
	if (s == e) {
		tree[node] = { diff, diff, true };
		return;
	}

	int m = (s + e) / 2;
	update(node * 2, s, m, idx, diff);
	update(node * 2 + 1, m + 1, e, idx, diff);

	tree[node] = { tree[node * 2].l, tree[node * 2 + 1].r, tree[node * 2].isSorted && tree[node * 2 + 1].isSorted && tree[node * 2].r <= tree[node * 2 + 1].l };
}

void func() {
	int q, l, r;
	while (M--) {
		cin >> q >> l >> r;
		if (q == 1) {
			if (query(1, 1, N, l, r).isSorted) {
				cout << "CS204\n";
			}
			else {
				cout << "HSS090\n";
			}
		}
		else {
			swap(list[l], list[r]);
			update(1, 1, N, l, list[l]);
			update(1, 1, N, r, list[r]);
		}
	}
}

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> list[i];
		update(1, 1, N, i, list[i]);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
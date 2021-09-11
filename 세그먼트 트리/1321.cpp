#include <iostream>
#define MAX 500001
using namespace std;

int list[MAX], tree[MAX * 4];
int N, M;

int init(int node, int s, int e) {
	if (s == e) {
		return tree[node] = list[s];
	}

	int m = (s + e) / 2;
	return tree[node] = init(node * 2, s, m) + init(node * 2 + 1, m + 1, e);
}

void update(int node, int s, int e, int idx, int diff) {
	if (idx < s || e < idx) return;
	if (s == e) {
		tree[node] += diff;
		return;
	}

	int m = (s + e) / 2;
	update(node * 2, s, m, idx, diff);
	update(node * 2 + 1, m + 1, e, idx, diff);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int node, int s, int e, int cnt) {
	if (s == e) return s;

	int m = (s + e) / 2;
	if (tree[node * 2] >= cnt) return query(node * 2, s, m, cnt);
	else return query(node * 2 + 1, m + 1, e, cnt - tree[node * 2]);
}

void func() {
	int type, x, y;
	cin >> M;
	while (M--) {
		cin >> type;
		if (type == 1) {
			cin >> x >> y;
			list[x] += y;
			update(1, 1, N, x, y);
		}
		else {
			cin >> x;
			cout << query(1, 1, N, x) << '\n';
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
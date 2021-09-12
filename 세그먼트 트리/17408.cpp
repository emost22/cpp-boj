#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;

int list[MAX], tree[MAX * 4];
int N, M;

int init(int node, int s, int e) {
	if (s == e) {
		return tree[node] = s;
	}

	int m = (s + e) / 2;
	int l = init(node * 2, s, m);
	int r = init(node * 2 + 1, m + 1, e);
	
	if (list[l] > list[r]) tree[node] = l;
	else tree[node] = r;

	return tree[node];
}

void update(int node, int s, int e, int idx) {
	if (idx < s || e < idx) return;
	if (s == e) {
		tree[node] = idx;
		return;
	}

	int m = (s + e) / 2;
	update(node * 2, s, m, idx);
	update(node * 2 + 1, m + 1, e, idx);
	
	int l = tree[node * 2];
	int r = tree[node * 2 + 1];
	if (list[l] > list[r]) tree[node] = l;
	else tree[node] = r;
}

int query(int node, int s, int e, int l, int r) {
	if (s > r || e < l) return 0;
	if (l <= s && e <= r) return tree[node];

	int m = (s + e) / 2;
	int ll = query(node * 2, s, m, l, r);
	int rr = query(node * 2 + 1, m + 1, e, l, r);

	if (list[ll] > list[rr]) return ll;
	else return rr;
}

void func() {
	int type, x, y;
	cin >> M;
	while (M--) {
		cin >> type >> x >> y;
		if (type == 1) {
			list[x] = y;
			update(1, 1, N, x);
		}
		else {
			int a = query(1, 1, N, x, y);
			int b = query(1, 1, N, x, a - 1);
			int c = query(1, 1, N, a + 1, y);

			cout << max(list[a] + list[b], list[a] + list[c]) << '\n';
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
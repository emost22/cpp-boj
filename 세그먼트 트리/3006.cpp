#include <iostream>
#define MAX 100000
using namespace std;

int list[MAX + 1], tree[(MAX + 1) * 4];
int N;

int init(int node, int s, int e) {
	if (s == e) {
		return tree[node] = 1;
	}

	int m = (s + e) / 2;
	return tree[node] = init(node * 2, s, m) + init(node * 2 + 1, m + 1, e);
}

void update(int node, int s, int e, int idx, int diff) {
	if (s > idx || idx > e) return;
	if (s == e) {
		tree[node] = diff;
		return;
	}

	int m = (s + e) / 2;
	update(node * 2, s, m, idx, diff);
	update(node * 2 + 1, m + 1, e, idx, diff);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int node, int s, int e, int l, int r) {
	if (l > e || s > r) return 0;
	if (l <= s && e <= r) return tree[node];

	int m = (s + e) / 2;
	return query(node * 2, s, m, l, r) + query(node * 2 + 1, m + 1, e, l, r);
}

void func() {
	int l = 1;
	int r = N;
	bool chk = true;
	for (int t = 0; t < N; t++) {
		if (chk) {
			cout << query(1, 1, N, 1, list[l] - 1) << '\n';
			update(1, 1, N, list[l], 0);
			l++;
		}
		else {
			cout << query(1, 1, N, list[r] + 1, N) << '\n';
			update(1, 1, N, list[r], 0);
			r--;
		}
		chk = !chk;
	}
}

void input() {
	int x;
	cin >> N;
	init(1, 1, N);
	for (int i = 1; i <= N; i++) {
		cin >> x;
		list[x] = i;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
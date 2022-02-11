#include <iostream>
#include <algorithm>
#define MAX 2000001
using namespace std;

int tree[MAX * 4];
int N;

void update(int node, int s, int e, int idx) {
	if (s > idx || e < idx) return;
	if (s == e) {
		tree[node]++;
		return;
	}

	int m = (s + e) / 2;
	update(node * 2, s, m, idx);
	update(node * 2 + 1, m + 1, e, idx);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int node, int s, int e, int k) {
	if (s == e) {
		tree[node]--;
		return s;
	}

	int m = (s + e) / 2;
	int ret = 0;
	if (tree[node * 2] >= k) ret = query(node * 2, s, m, k);
	else ret = query(node * 2 + 1, m + 1, e, k - tree[node * 2]);

	tree[node] = tree[node * 2] + tree[node * 2 + 1];
	return ret;
}

void func() {
	int type, x;
	for (int i = 0; i < N; i++) {
		cin >> type >> x;

		if (type == 1) {
			update(1, 1, MAX - 1, x);
		}
		else {
			cout << query(1, 1, MAX - 1, x) << '\n';
		}
	}
}

void input() {
	cin >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
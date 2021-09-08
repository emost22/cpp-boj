#include <iostream>
#define MAX 100000
using namespace std;

int list[MAX + 1], tree[(MAX + 1) * 4];
int cnt[MAX + 1];
int N;

int init(int node, int s, int e) {
	if (s == e) {
		return tree[node] = 1;
	}

	int m = (s + e) / 2;
	return tree[node] = init(node * 2, s, m) + init(node * 2 + 1, m + 1, e);
}

void query(int node, int s, int e, int idx, int k) {
	if (s == e) {
		tree[node] = 0;
		list[s] = idx;
		return;
	}

	int m = (s + e) / 2;
	if (k <= tree[node * 2]) query(node * 2, s, m, idx, k);
	else query(node * 2 + 1, m + 1, e, idx, k - tree[node * 2]);

	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void func() {
	for (int i = 1; i <= N; i++) {
		query(1, 1, N, i, cnt[i] + 1);
	}

	for (int i = 1; i <= N; i++) {
		cout << list[i] << '\n';
	}
}

void input() {
	cin >> N;
	init(1, 1, N);
	for (int i = 1; i <= N; i++) {
		cin >> cnt[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
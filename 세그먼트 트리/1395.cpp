#include <iostream>
using namespace std;

int N, M;
int tree[400004];
bool lazy[400004];

void lazy_update(int node, int s, int e) {
	lazy[node] = false;
	tree[node] = (e - s + 1) - tree[node];
	if (s != e) {
		lazy[node * 2] = !lazy[node * 2];
		lazy[node * 2 + 1] = !lazy[node * 2 + 1];
	}
}

int update(int node, int s, int e, int l, int r) {
	if (lazy[node]) {
		lazy_update(node, s, e);
	}
	if (l <= s && e <= r) {
		if (s != e) {
			lazy[node * 2] = !lazy[node * 2];
			lazy[node * 2 + 1] = !lazy[node * 2 + 1];
		}
		return tree[node] = (e - s + 1) - tree[node];
	}
	if (s > r || l > e) return tree[node];

	int m = (s + e) / 2;
	return tree[node] = update(node * 2, s, m, l, r) + update(node * 2 + 1, m + 1, e, l, r);
}

int findon(int node, int s, int e, int l, int r) {
	if (lazy[node]) {
		lazy_update(node, s, e);
	}
	if (l <= s && e <= r) {
		return tree[node];
	}
	if (s > r || l > e) return 0;

	int m = (s + e) / 2;
	return findon(node * 2, s, m, l, r) + findon(node * 2 + 1, m + 1, e, l, r);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	int t, a, b;
	cin >> N >> M;
	while (M--) {
		cin >> t >> a >> b;
		if (t) {
			cout << findon(1, 1, N, a, b) << '\n';
		}
		else {
			update(1, 1, N, a, b);
		}
	}

	return 0;
}
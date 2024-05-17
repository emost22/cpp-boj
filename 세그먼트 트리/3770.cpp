#include <iostream>
#include <vector>
#include <cstring>
#define MAX 1001
using namespace std;
typedef long long ll;

vector<int> v[MAX];
ll tree[MAX << 2];
int list[MAX];
int N, M, K;

ll update(int node, int l, int r, int idx) {
	if (idx < l || idx > r) return tree[node];
	if (l == r) return ++tree[node];

	int m = (l + r) >> 1;
	return tree[node] = update(node << 1, l, m, idx) + update((node << 1) + 1, m + 1, r, idx);
}

ll query(int node, int l, int r, int s, int e) {
	if (s > r || e < l) return 0LL;
	if (s <= l && r <= e) return tree[node];

	int m = (l + r) >> 1;
	return query(node << 1, l, m, s, e) + query((node << 1) + 1, m + 1, r, s, e);
}

void init() {
	memset(tree, 0LL, sizeof(tree));
	for (int i = 1; i <= N; i++) {
		v[i].clear();
	}
}

void func(int tc) {
	ll ret = 0LL;
	for (int i = 1; i <= N; i++) {
		for (auto x : v[i]) {
			ret += query(1, 1, M, x + 1, M);
		}

		for (auto x : v[i]) {
			update(1, 1, M, x);
		}
	}

	cout << "Test case " << tc << ": " << ret << '\n';
}

void input() {
	int x, y;
	cin >> N >> M >> K;
	while (K--) {
		cin >> x >> y;
		v[x].push_back(y);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		input();
		func(t);
		init();
	}

	return 0;
}
#include <iostream>
#include <unordered_map>
#include <string>
#include <cstring>
#define MAX 100001
using namespace std;
typedef long long ll;

unordered_map<string, int> m;
int idxList[MAX];
ll tree[MAX << 2];
int N;

void init() {
	m.clear();
	memset(tree, 0, sizeof(tree));
}

ll update(int node, int l, int r, int idx, int diff) {
	if (idx < l || r < idx) return tree[node];
	if (l == r) return ++tree[node];

	int m = (l + r) >> 1;
	return tree[node] = update(node << 1, l, m, idx, diff) + update((node << 1) + 1, m + 1, r, idx, diff);
}

ll query(int node, int l, int r, int s, int e) {
	if (l > e || r < s) return 0LL;
	if (s <= l && r <= e) return tree[node];

	int m = (l + r) >> 1;
	return query(node << 1, l, m, s, e) + query((node << 1) + 1, m + 1, r, s, e);
}

void func() {
	ll ret = 0LL;
	for (int i = 0; i < N; i++) {
		ret += query(1, 1, N, idxList[i] + 1, N);
		update(1, 1, N, idxList[i], 1);
	}
	cout << ret << '\n';
}

void input() {
	cin >> N;
	if (!N) exit(0);
	
	string str;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		cin >> str;
		m[str] = ++cnt;
	}

	for (int i = 0; i < N; i++) {
		cin >> str;
		idxList[i] = m[str];
	}
}

int main() {
	cin.tie(nullptr); cout.tie(nullptr);
	ios::sync_with_stdio(false);

	while (1) {
		input();
		func();
		init();
	}

	return 0;
}
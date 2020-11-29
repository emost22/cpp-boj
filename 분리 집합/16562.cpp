#include <iostream>
#include <algorithm>
using namespace std;

int N, M, K;
int cost[10001], parent[10001];

void init() {
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}
}

int find(int v) {
	if (v == parent[v]) return v;
	cost[parent[v]] = min(cost[parent[v]], cost[v]);
	return parent[v] = find(parent[v]);
}

void solve() {
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		int p = find(i);
		if (p != i) continue;
		ans += cost[i];
	}
	if (K >= ans) cout << ans << '\n';
	else cout << "Oh no\n";
}

void input() {
	int u, v;
	cin >> N >> M >> K;
	init();
	for (int i = 1; i <= N; i++) {
		cin >> cost[i];
	}

	while (M--) {
		cin >> u >> v;
		u = find(u);
		v = find(v);

		if (u != v) {
			parent[v] = u;
			cost[u] = min(cost[u], cost[v]);
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	solve();

	return 0;
}
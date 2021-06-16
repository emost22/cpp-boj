#include <iostream>
#include <vector>
#define MAX 1000
#define LOG 11
using namespace std;

vector<pair<int, int> > graph[MAX + 1];
pair<int, int> parent[MAX + 1][LOG];
int depth[MAX + 1];
int N, M;

void dfs(int v, int d) {
	depth[v] = d;

	for (int i = 0; i < graph[v].size(); i++) {
		int next = graph[v][i].first;
		int w = graph[v][i].second;

		if (depth[next]) continue;
		parent[next][0] = { v, w };
		dfs(next, d + 1);
	}
}

int lca(int u, int v) {
	int ans = 0;
	if (depth[u] > depth[v]) swap(u, v);

	for (int i = LOG - 1; i >= 0; i--) {
		if (depth[v] - depth[u] >= (1 << i)) {
			ans += parent[v][i].second;
			v = parent[v][i].first;
		}
	}
	if (u == v) return ans;

	for (int i = LOG - 1; i >= 0; i--) {
		if (parent[u][i].first != parent[v][i].first) {
			ans += (parent[u][i].second + parent[v][i].second);
			u = parent[u][i].first;
			v = parent[v][i].first;
		}
	}

	return ans + (parent[u][0].second + parent[v][0].second);
}

void func() {
	for (int j = 1; j < LOG; j++) {
		for (int i = 1; i <= N; i++) {
			parent[i][j].first = parent[parent[i][j - 1].first][j - 1].first;
			if (!parent[i][j].first) continue;
			parent[i][j].second = parent[i][j - 1].second + parent[parent[i][j - 1].first][j - 1].second;
		}
	}

	int u, v;
	while (M--) {
		cin >> u >> v;
		cout << lca(u, v) << '\n';
	}
}

void input() {
	int u, v, w;
	cin >> N >> M;
	for (int i = 0; i < N - 1; i++) {
		cin >> u >> v >> w;
		graph[u].push_back({ v,w });
		graph[v].push_back({ u,w });
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	dfs(1, 1);
	func();

	return 0;
}
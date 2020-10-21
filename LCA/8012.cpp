#include <iostream>
#include <vector>
#define MAX 30001
#define LOG 16
using namespace std;

vector<int> graph[MAX];
int depth[MAX], parent[MAX][LOG];
bool visit[MAX];
int N, M, ans;

void dfs(int v, int d) {
	visit[v] = true;
	depth[v] = d;
	for (int i = 0; i < graph[v].size(); i++) {
		int next = graph[v][i];
		if (visit[next]) continue;
		parent[next][0] = v;
		dfs(next, d + 1);
	}
}

void func() {
	dfs(1, 0);
	for (int j = 1; j < LOG; j++) {
		for (int i = 1; i <= N; i++) {
			parent[i][j] = parent[parent[i][j - 1]][j - 1];
		}
	}
}

int lca(int x, int y) {
	int dis = 0;
	if (depth[x] > depth[y]) swap(x, y);

	for (int i = LOG - 1; i >= 0; i--) {
		if (depth[y] - depth[x] >= (1 << i)) {
			dis += depth[y] - depth[parent[y][i]];
			y = parent[y][i];
		}
	}

	if (x == y) return dis;

	for (int i = LOG - 1; i >= 0; i--) {
		if (parent[x][i] != parent[y][i]) {
			dis += (2 * (depth[x] - depth[parent[x][i]]));
			x = parent[x][i];
			y = parent[y][i];
		}
	}

	return dis + 2;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int u, v;
	cin >> N;
	for (int i = 1; i < N; i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	func();

	int prev = 1;
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> v;
		ans += lca(prev, v);
		prev = v;
	}

	cout << ans << '\n';

	return 0;
}
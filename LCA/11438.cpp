#include <iostream>
#include <vector>
#define MAX 100001
#define LOG 18
using namespace std;

vector<int> graph[MAX];
int parent[MAX][LOG], depth[MAX];
bool visit[MAX];
int N, M;

void dfs(int v, int dep) {
	visit[v] = true;
	depth[v] = dep;
	for (int i = 0; i < graph[v].size(); i++) {
		int next = graph[v][i];
		if (visit[next]) continue;
		parent[next][0] = v;
		dfs(next, dep + 1);
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
	if (depth[x] > depth[y]) swap(x, y);

	for (int i = LOG - 1; i >= 0; i--) {
		if (depth[y] - depth[x] >= (1 << i)) {
			y = parent[y][i];
		}
	}

	if (x == y) return x;
	for (int i = LOG - 1; i >= 0; i--) {
		if (parent[x][i] != parent[y][i]) {
			x = parent[x][i];
			y = parent[y][i];
		}
	}

	return parent[x][0];
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
	
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		cout << lca(u, v) << '\n';
	}

	return 0;
}
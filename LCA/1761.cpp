#include <iostream>
#include <vector>
#define MAX 40001
#define LOG 17
using namespace std;

vector<pair<int, int> > graph[MAX];
int depth[MAX];
pair<int, int> parent[MAX][LOG];
bool visit[MAX];
int N, M;

void dfs(int v, int dep) {
	visit[v] = true;
	depth[v] = dep;
	for (int i = 0; i < graph[v].size(); i++) {
		int next = graph[v][i].first;
		int dis = graph[v][i].second;
		if (visit[next]) continue;
		parent[next][0].first = v;
		parent[next][0].second = dis;
		dfs(next, dep + 1);
	}
}

void func() {
	dfs(1, 0);
	for (int j = 1; j < LOG; j++) {
		for (int i = 1; i <= N; i++) {
			parent[i][j].first = parent[parent[i][j - 1].first][j - 1].first;
			parent[i][j].second = parent[i][j - 1].second + parent[parent[i][j - 1].first][j - 1].second;
		}
	}
}

int lca(int x, int y) {
	int dis = 0;
	if (depth[x] > depth[y]) swap(x, y);

	for (int i = LOG - 1; i >= 0; i--) {
		if (depth[y] - depth[x] >= (1 << i)) {
			dis += parent[y][i].second;
			y = parent[y][i].first;
		}
	}

	if (x == y) return dis;
	for (int i = LOG - 1; i >= 0; i--) {
		if (parent[x][i].first != parent[y][i].first) {
			dis += parent[x][i].second;
			dis += parent[y][i].second;
			x = parent[x][i].first;
			y = parent[y][i].first;
		}
	}

	return dis + parent[x][0].second + parent[y][0].second;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int u, v, w;
	cin >> N;
	for (int i = 1; i < N; i++) {
		cin >> u >> v >> w;
		graph[u].push_back({ v,w });
		graph[v].push_back({ u,w });
	}
	func();

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		cout << lca(u, v) << '\n';
	}

	return 0;
}
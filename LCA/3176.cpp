#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1000000000
#define MAX 100001
#define LOG 18
using namespace std;

vector<pair<int, int> > graph[MAX];
int parent[MAX][LOG];
pair<int, int> length[MAX][LOG];
bool visit[MAX];
int depth[MAX], N, M;

void dfs(int v, int d) {
	visit[v] = true;
	depth[v] = d;
	for (int i = 0; i < graph[v].size(); i++) {
		int next = graph[v][i].first;
		int dis = graph[v][i].second;
		if (visit[next]) continue;
		parent[next][0] = v;
		length[next][0].first = dis;
		length[next][0].second = dis;
		dfs(next, d + 1);
	}
}

void func() {
	dfs(1, 0);
	for (int j = 1; j < LOG; j++) {
		for (int i = 1; i <= N; i++) {
			parent[i][j] = parent[parent[i][j - 1]][j - 1];
			length[i][j].first = min(length[i][j - 1].first, length[parent[i][j - 1]][j - 1].first);
			length[i][j].second = max(length[i][j - 1].second, length[parent[i][j - 1]][j - 1].second);
		}
	}
}

pair<int, int> lca(int x, int y) {
	int minlength = INF;
	int maxlength = -INF;

	if (depth[x] > depth[y]) swap(x, y);

	for (int i = LOG - 1; i >= 0; i--) {
		if (depth[y] - depth[x] >= (1 << i)) {
			minlength = min(minlength, length[y][i].first);
			maxlength = max(maxlength, length[y][i].second);
			y = parent[y][i];
		}
	}

	if (x == y) return { minlength, maxlength };

	for (int i = LOG - 1; i >= 0; i--) {
		if (parent[x][i] != parent[y][i]) {
			minlength = min(minlength, length[x][i].first);
			minlength = min(minlength, length[y][i].first);
			maxlength = max(maxlength, length[x][i].second);
			maxlength = max(maxlength, length[y][i].second);
			x = parent[x][i];
			y = parent[y][i];
		}
	}

	minlength = min(minlength, length[x][0].first);
	minlength = min(minlength, length[y][0].first);
	maxlength = max(maxlength, length[x][0].second);
	maxlength = max(maxlength, length[y][0].second);

	return { minlength, maxlength };
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
		pair<int, int> p = lca(u, v);

		cout << p.first << ' ' << p.second << '\n';
	}

	return 0;
}
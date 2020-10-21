#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100001
#define LOG 18
using namespace std;
typedef long long ll;

vector<pair<int, int> > graph[MAX];
bool visit[MAX];
pair<int, ll> parent[MAX][LOG];
int depth[MAX];
int N, M, lcanode;

void dfs(int v, int d) {
	visit[v] = true;
	depth[v] = d;
	for (int i = 0; i < graph[v].size(); i++) {
		int next = graph[v][i].first;
		int dis = graph[v][i].second;
		if (visit[next]) continue;
		parent[next][0].first = v;
		parent[next][0].second = dis;
		dfs(next, d + 1);
	}
}

void func() {
	dfs(1, 0);
	for (int j = 1; j < LOG; j++) {
		for (int i = 1; i <= N; i++) {
			parent[i][j].first = parent[parent[i][j - 1].first][j - 1].first;
			if (parent[i][j].first == 0) continue;
			parent[i][j].second = parent[i][j - 1].second + parent[parent[i][j - 1].first][j - 1].second;
		}
	}
}

ll lca(int x, int y) {
	ll sum = 0;
	if (depth[x] > depth[y]) swap(x, y);

	for (int i = LOG - 1; i >= 0; i--) {
		if (depth[y] - depth[x] >= (1 << i)) {
			sum += parent[y][i].second;
			y = parent[y][i].first;
		}
	}

	if (x == y) {
		lcanode = x;
		return sum;
	}

	for (int i = LOG - 1; i >= 0; i--) {
		if (parent[x][i].first == 0) continue;

		if (parent[x][i].first != parent[y][i].first) {
			sum += parent[x][i].second;
			sum += parent[y][i].second;
			x = parent[x][i].first;
			y = parent[y][i].first;
		}
	}

	sum += (parent[x][0].second + parent[y][0].second);
	lcanode = parent[x][0].first;
	return sum;
}

int lca2(int x, int y, int k) {
	lca(x, y);
	if (depth[x] - depth[lcanode] + 1 >= k) { //¿ÞÂÊ
		k--;
		for (int i = LOG - 1; i >= 0; i--) {
			if (parent[x][i].first == 0) continue;
			if (depth[x] - depth[parent[x][i].first] <= k) {
				k -= (depth[x] - depth[parent[x][i].first]);
				x = parent[x][i].first;
			}
		}

		return x;
	}
	else { //¿À¸¥ÂÊ
		int d = depth[y] - depth[lcanode];
		k -= (depth[x] - depth[lcanode] + 1);
		for (int i = LOG - 1; i >= 0; i--) {
			if (parent[y][i].first == 0) continue;
			if (depth[y] - depth[parent[y][i].first] <= d - k) {
				k += (depth[y] - depth[parent[y][i].first]);
				y = parent[y][i].first;
			}
		}

		return y;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int u, v, w, type;
	cin >> N;
	for (int i = 1; i < N; i++) {
		cin >> u >> v >> w;
		graph[u].push_back({ v,w });
		graph[v].push_back({ u,w });
	}
	func();

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> type;
		if (type == 1) {
			cin >> u >> v;
			cout << lca(u, v) << '\n';
		}
		else {
			cin >> u >> v >> w;
			cout << lca2(u, v, w) << '\n';
		}
	}
	
	return 0;
}
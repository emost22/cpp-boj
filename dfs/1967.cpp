#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<pair<int, int> > graph[10001];
int visit[10001], N, point, height;

void dfs(int v, int w) {
	visit[v] = 1;

	if (height < w) {
		height = w;
		point = v;
	}

	for (int i = 0; i < graph[v].size(); i++) {
		if (!visit[graph[v][i].first]) {
			dfs(graph[v][i].first, w + graph[v][i].second);
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int v, u, w;

	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		cin >> v >> u >> w;
		graph[v].push_back(make_pair(u, w));
		graph[u].push_back(make_pair(v, w));
	}

	dfs(1, 0);
	memset(visit, 0, sizeof(visit));
	dfs(point, 0);
	cout << height << '\n';

	return 0;
}
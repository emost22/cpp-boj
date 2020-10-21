#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<pair<int, int> > graph[100001];
int visit[100001];
int N, length, point;

void dfs(int v, int w) {
	visit[v] = 1;

	if (length < w) {
		length = w;
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
	for (int i = 0; i < N; i++) {
		cin >> v;
		while (1) {
			cin >> u;
			if (u == -1) break;
			cin >> w;

			graph[v].push_back(make_pair(u, w));
		}
	}

	dfs(1, 0);
	memset(visit, 0, sizeof(visit));
	dfs(point, 0);
	cout << length << '\n';

	return 0;
}
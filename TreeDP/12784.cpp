#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define MAX 1001
using namespace std;
typedef pair<int, int> pi;

vector<pi> graph[MAX];
bool visit[MAX];
int N, M;

int dfs(int v) {
	int ret = 0;
	int sum = 0;
	visit[v] = true;
	if (graph[v].size() == 1) return graph[v][0].second;

	for (int i = 0; i < graph[v].size(); i++) {
		int next = graph[v][i].first;
		
		if (visit[next]) {
			ret = graph[v][i].second;
			continue;
		}

		sum += dfs(next);
	}

	return min(ret, sum);
}

void func() {
	int ans = 0;

	for (int i = 0; i < graph[1].size(); i++) {
		int x = graph[1][i].first;
		ans += dfs(x);
	}

	cout << ans << '\n';
}

void input() {
	int u, v, w;
	cin >> N >> M;
	while (M--) {
		cin >> u >> v >> w;
		graph[u].push_back({ v,w });
		graph[v].push_back({ u,w });
	}
	visit[1] = true;
}

void init() {
	for (int i = 1; i <= N; i++) {
		graph[i].clear();
	}
	memset(visit, false, sizeof(visit));
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
		init();
	}

	return 0;
}
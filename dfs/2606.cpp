#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[101];
bool visit[101];
int N, M, ans;

void dfs(int v) {
	visit[v] = true;
	ans++;

	for (int i = 0; i < graph[v].size(); i++) {
		int next = graph[v][i];

		if (visit[next]) continue;
		dfs(next);
	}
}

void input() {
	int u, v;
	cin >> N >> M;
	while (M--) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	dfs(1);
	cout << ans - 1 << '\n';

	return 0;
}
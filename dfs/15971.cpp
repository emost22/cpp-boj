#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 100001
using namespace std;
typedef pair<int, int> pi;

vector<pi> graph[MAX];
bool visit[MAX];
int N, S, E;
int ans, len;

void dfs(int v, int sum, int maxLen) {
	visit[v] = true;
	if (v == E) {
		ans = max(ans, sum);
		len = max(len, maxLen);
		return;
	}

	for (int i = 0; i < graph[v].size(); i++) {
		int next = graph[v][i].first;
		int nextw = graph[v][i].second;

		if (visit[next]) continue;

		dfs(next, sum + nextw, max(maxLen, nextw));
		visit[next] = false;
	}
}

void func() {
	dfs(S, 0, 0);
	cout << ans - len << '\n';
}

void input() {
	int u, v, w;
	cin >> N >> S >> E;
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
	func();

	return 0;
}
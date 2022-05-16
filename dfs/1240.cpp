#include <iostream>
#include <vector>
#include <cstring>
#define MAX 1001
using namespace std;
typedef pair<int, int> pi;

vector<pi> graph[MAX];
bool visit[MAX];
int N, M, S, E;

bool dfs(int v, int sum) {
	if (v == E) {
		cout << sum << '\n';
		return true;
	}
	visit[v] = true;

	for (int i = 0; i < graph[v].size(); i++) {
		int next = graph[v][i].first;
		int nextw = graph[v][i].second;

		if (visit[next]) continue;

		if (dfs(next, sum + nextw)) return true;
	}

	return false;
}

void func() {
	while (M--) {
		cin >> S >> E;
		dfs(S, 0);
		memset(visit, false, sizeof(visit));
	}
}

void input() {
	int u, v, w;
	cin >> N >> M;
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
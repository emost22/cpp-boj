#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100001
using namespace std;

vector<int> graph[MAX];
int visit[MAX];
int N, M, S, cnt;

void dfs(int v) {
	visit[v] = ++cnt;

	for (int i = 0; i < graph[v].size(); i++) {
		int next = graph[v][i];

		if (visit[next]) continue;
		dfs(next);
	}
}

void func() {
	for (int i = 1; i <= N; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(S);

	for (int i = 1; i <= N; i++) {
		cout << visit[i] << '\n';
	}
}

void input() {
	int u, v;
	cin >> N >> M >> S;
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
	func();

	return 0;
}
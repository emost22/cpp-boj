#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 100001
using namespace std;

vector<int> graph[MAX];
int visit[MAX];
int N, M, S;

void dfs(int v, int d) {
	visit[v] = d;

	for (int i = 0; i < graph[v].size(); i++) {
		int next = graph[v][i];

		if (visit[next] != -1) continue;

		dfs(next, d + 1);
	}
}

void func() {
	for (int i = 1; i <= N; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	memset(visit, -1, sizeof(visit));
	dfs(S, 0);

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
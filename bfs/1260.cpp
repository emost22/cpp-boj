#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> graph[1001];
int visit[1001], N, M, V;

void dfs(int n) {
	visit[n] = 1;
	cout << n << ' ';

	sort(graph[n].begin(), graph[n].end());
	for (int i = 0; i < graph[n].size(); i++) {
		if (!visit[graph[n][i]]) {
			dfs(graph[n][i]);
		}
	}
}

void bfs(int n) {
	queue<int> q;
	int v;
	q.push(n);
	visit[n] = 0;

	while (!q.empty()) {
		v = q.front();
		cout << v << ' ';
		q.pop();

		for (int i = 0; i < graph[v].size(); i++) {
			if (visit[graph[v][i]]) {
				visit[graph[v][i]] = 0;
				q.push(graph[v][i]);
			}
		}
	}
}

int main() {
	int a, b;

	cin >> N >> M >> V;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	dfs(V);
	cout << '\n';
	bfs(V);
	cout << '\n';

	return 0;
}
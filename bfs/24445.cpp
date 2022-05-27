#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 100001
using namespace std;

vector<int> graph[MAX];
int visit[MAX];
int N, M, S;

void bfs() {
	queue<int> q;
	q.push(S);
	visit[S] = 1;
	int cnt = 2;
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < graph[x].size(); i++) {
			int next = graph[x][i];

			if (visit[next]) continue;

			q.push(next);
			visit[next] = cnt++;
		}
	}
}

void func() {
	for (int i = 1; i <= N; i++) {
		sort(graph[i].begin(), graph[i].end(), [](int a, int b) {
			return a > b;
		});
	}

	bfs();
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
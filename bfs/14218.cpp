#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#define MAX 1001
using namespace std;

vector<int> graph[MAX];
int dis[MAX];
int N, M, Q;

void bfs() {
	memset(dis, -1, sizeof(dis));
	queue<int> q;
	q.push(1);
	dis[1] = 0;

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (auto next : graph[x]) {
			if (dis[next] != -1) continue;

			q.push(next);
			dis[next] = dis[x] + 1;
		}
	}
}

void func() {
	int u, v;
	cin >> Q;
	while (Q--) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);

		bfs();
		for (int i = 1; i <= N; i++) {
			cout << dis[i] << ' ';
		}
		cout << '\n';
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
	func();

	return 0;
}
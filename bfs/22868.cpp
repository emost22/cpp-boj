#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#define MAX 10001
using namespace std;

vector<int> graph[MAX];
int parent[MAX];
bool visit[MAX];
int N, M, S, E, ans;

void comeBfs() {
	queue<int> q;
	memset(visit, false, sizeof(visit));
	for (int i = E; i != S; i = parent[i]) {
		visit[i] = true;
	}
	q.push(E);

	for (int t = 0; !q.empty(); t++) {
		int qsize = q.size();
		while (qsize--) {
			int x = q.front();
			q.pop();

			if (x == S) {
				ans += t;
				return;
			}

			for (int i = 0; i < graph[x].size(); i++) {
				int next = graph[x][i];

				if (visit[next]) continue;

				q.push(next);
				visit[next] = true;
			}
		}
	}
}

void goBfs() {
	queue<int> q;
	q.push(S);
	visit[S] = true;
	for (int t = 0; !q.empty(); t++) {
		int qsize = q.size();
		while (qsize--) {
			int x = q.front();
			q.pop();

			if (x == E) {
				ans += t;
				return;
			}

			for (int i = 0; i < graph[x].size(); i++) {
				int next = graph[x][i];

				if (visit[next]) continue;

				q.push(next);
				visit[next] = true;
				parent[next] = x;
			}
		}
	}
}

void func() {
	for (int i = 1; i <= N; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	goBfs();
	comeBfs();
	cout << ans << '\n';
}

void input() {
	int u, v;
	cin >> N >> M;
	while (M--) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	cin >> S >> E;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
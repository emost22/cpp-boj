#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>
#define MAX 100001
using namespace std;

vector<int> graph[MAX];
int visit[MAX];
int N, M, S;

void bfs() {
	queue<int> q;
	q.push(S);
	visit[S] = 0;
	for (int t = 1; !q.empty(); t++) {
		int qsize = q.size();
		while (qsize--) {
			int x = q.front();
			q.pop();

			for (int i = 0; i < graph[x].size(); i++) {
				int next = graph[x][i];

				if (visit[next] != -1) continue;
				visit[next] = t;
				q.push(next);
			}
		}
	}
}

void func() {
	memset(visit, -1, sizeof(visit));
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
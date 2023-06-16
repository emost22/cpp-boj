#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <cstring>
#define MAX 1001
using namespace std;

int dis[MAX][MAX];
string list[MAX];
int parent[MAX];
int N, M, S, E;

void init() {
	for (int i = 1; i < N; i++) {
		for (int j = i + 1; j <= N; j++) {
			if (i == j) continue;
			int ret = 0;
			for (int k = 0; k < M; k++) {
				if (list[i][k] == list[j][k]) continue;

				ret++;
			}

			dis[i][j] = dis[j][i] = ret;
		}
	}
}

void bfs() {
	memset(parent, -1, sizeof(parent));

	queue<int> q;
	q.push(S);
	parent[S] = 0;

	while (!q.empty()) {
		int idx = q.front();
		q.pop();

		for (int i = 1; i <= N; i++) {
			if (parent[i] != -1) continue;
			if (dis[idx][i] != 1) continue;

			parent[i] = idx;
			q.push(i);
			if (i == E) return;
		}
	}
}

void func() {
	init();
	bfs();

	if (parent[E] == -1) {
		cout << "-1\n";
		return;
	}

	stack<int> ans;
	for (int i = E; ; i = parent[i]) {
		ans.push(i);
		if (!parent[i]) break;
	}

	while (!ans.empty()) {
		cout << ans.top() << ' ';
		ans.pop();
	}

	cout << '\n';
}

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> list[i];
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
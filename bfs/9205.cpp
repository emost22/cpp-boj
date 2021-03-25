#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

vector<int> graph[103];
int list[103][2];
bool visit[103];
int N;

void bfs() {
	queue<int> q;
	q.push(1);
	visit[1] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < graph[x].size(); i++) {
			int next = graph[x][i];

			if (visit[next]) continue;

			q.push(next);
			visit[next] = true;
		}
	}

	if (visit[N + 2]) cout << "happy\n";
	else cout << "sad\n";
}

int getDis(int a[2], int b[2]) {
	return abs(a[0] - b[0]) + abs(a[1] - b[1]);
}

void func() {
	for (int i = 1; i <= N + 1; i++) {
		for (int j = i + 1; j <= N + 2; j++) {
			int dis = getDis(list[i], list[j]);
			if (dis <= 1000) {
				graph[i].push_back(j);
				graph[j].push_back(i);
			}
		}
	}
}

void input() {
	cin >> N;
	for (int i = 1; i <= N + 2; i++) {
		cin >> list[i][0] >> list[i][1];
	}
}

void init() {
	memset(visit, false, sizeof(visit));
	for (int i = 1; i <= N + 2; i++) {
		graph[i].clear();
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
		bfs();
		init();
	}

	return 0;
}
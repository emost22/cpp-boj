#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 200001
using namespace std;

queue<int> q;
vector<int> graph[MAX];
bool visit[MAX];
int friends[MAX], conn[MAX], ans[MAX];
int N, M;

void bfs() {
	for (int t = 1; !q.empty(); t++) {
		int qsize = q.size();
		while (qsize--) {
			int x = q.front();
			q.pop();

			for (int i = 0; i < graph[x].size(); i++) {
				int next = graph[x][i];

				if (visit[next]) continue;

				conn[next]++;
				if (friends[next] <= conn[next] * 2) {
					q.push(next);
					ans[next] = t;
					visit[next] = true;
				}
			}
		}
	}
}

void func() {
	bfs();
	for (int i = 1; i <= N; i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
}

void input() {
	int x;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		while (1) {
			cin >> x;
			if (!x) break;

			graph[i].push_back(x);
			friends[i]++;
		}
	}

	memset(ans, -1, sizeof(ans));
	cin >> M;
	while (M--) {
		cin >> x;
		q.push(x);
		ans[x] = 0;
		visit[x] = true;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
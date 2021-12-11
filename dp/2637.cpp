#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define MAX 101
using namespace std;
typedef pair<int, int> pi;

vector<pi> graph[MAX];
int dp[MAX][MAX];
int conn[MAX];
int N, M;

void bfs() {
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (!conn[i]) {
			q.push(i);
			dp[i][i] = 1;
		}
	}

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < graph[x].size(); i++) {
			int next = graph[x][i].first;
			int k = graph[x][i].second;
			for (int j = 1; j <= N; j++) {
				dp[next][j] += (k * dp[x][j]);
			}

			conn[next]--;
			if (!conn[next]) q.push(next);
		}
	}

	for (int i = 1; i <= N; i++) {
		if (dp[N][i]) cout << i << ' ' << dp[N][i] << '\n';
	}
}

void input() {
	int x, y, k;
	cin >> N >> M;
	while (M--) {
		cin >> x >> y >> k;
		conn[x]++;
		graph[y].push_back({ x,k });
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	bfs();

	return 0;
}
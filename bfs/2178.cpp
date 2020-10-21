#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;

queue<pair<int, int> > q;
int x_direct[] = { 0,1,0,-1 }, y_direct[] = { 1,0,-1,0 };
int map[101][101], visit[101][101], dp[101][101], N, M;

void bfs(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int xx = x + x_direct[i];
		int yy = y + y_direct[i];

		if (xx <= 0 || yy <= 0 || xx > N || yy > M) continue;
		if (!map[xx][yy] || visit[xx][yy]) continue;

		dp[xx][yy] = dp[x][y] + 1;
		q.push(make_pair(xx, yy));
		visit[xx][yy] = 1;
	}
}

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	q.push(make_pair(1, 1));
	visit[1][1] = 1;
	dp[1][1] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		bfs(x, y);
	}

	cout << dp[N][M] << '\n';

	return 0;
}
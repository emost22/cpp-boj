#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, K;
int direct[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0 } };
bool list[101][101], visit[101][101];

int bfs(int sx, int sy) {
	int cnt = 0;
	queue<pair<int, int> > q;
	q.push({sx, sy});
	visit[sx][sy] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		cnt++;
		for (int i = 0; i < 4; i++) {
			int nx = x + direct[i][0];
			int ny = y + direct[i][1];

			if (nx <= 0 || ny <= 0 || nx > N || ny > M) continue;
			if (!list[nx][ny] || visit[nx][ny]) continue;

			q.push({ nx, ny });
			visit[nx][ny] = true;
		}
	}

	return cnt;
}

void func() {
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (visit[i][j] || !list[i][j]) continue;

			ans = max(ans, bfs(i, j));
		}
	}

	cout << ans << '\n';
}

void input() {
	int x, y;
	cin >> N >> M >> K;
	while (K--) {
		cin >> x >> y;
		list[x][y] = true;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
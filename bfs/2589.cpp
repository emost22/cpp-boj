#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

typedef struct Point {
	int x;
	int y;
	int cnt;
}Point;

char list[60][60];
bool visit[60][60];
int direct[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int N, M, ans;

void bfs(int sx, int sy) {
	queue<Point> q;
	q.push({ sx,sy,0 });
	visit[sx][sy] = true;
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int cnt = q.front().cnt;
		q.pop();

		ans = max(ans, cnt);
		for (int i = 0; i < 4; i++) {
			int nx = x + direct[i][0];
			int ny = y + direct[i][1];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (visit[nx][ny] || list[nx][ny] == 'W') continue;

			q.push({ nx,ny,cnt + 1 });
			visit[nx][ny] = true;
		}
	}
}

void func() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (list[i][j] == 'W') continue;

			bfs(i, j);
			memset(visit, false, sizeof(visit));
		}
	}

	cout << ans << '\n';
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> list[i][j];
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
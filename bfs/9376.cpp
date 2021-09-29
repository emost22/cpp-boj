#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#define MAX 102
using namespace std;

char list[MAX][MAX];
queue<pair<int, int> > sq;
priority_queue<pair<int, pair<int, int> > > q;
int d[MAX][MAX][3];
int direct[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int N, M;

void func() {
	int ans = 2147483647;
	for (int i = 0; i < N + 2; i++) {
		for (int j = 0; j < M + 2; j++) {
			if (list[i][j] == '*' || d[i][j][0] == -1) continue;

			int sum = d[i][j][0] + d[i][j][1] + d[i][j][2];
			if (list[i][j] == '#') sum -= 2;

			ans = min(ans, sum);
		}
	}

	cout << ans << '\n';
}

void bfs() {
	for (int k = 0; k < 3; k++) {
		int sx = sq.front().first;
		int sy = sq.front().second;
		sq.pop();

		q.push({ 0, {sx,sy} });
		d[sx][sy][k] = 0;
		while (!q.empty()) {
			int x = q.top().second.first;
			int y = q.top().second.second;
			int cnt = -q.top().first;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + direct[i][0];
				int ny = y + direct[i][1];

				if (nx < 0 || ny < 0 || nx > N + 1 || ny > M + 1) continue;
				if (d[nx][ny][k] != -1 || list[nx][ny] == '*') continue;

				if (list[nx][ny] == '.') {
					q.push({ -cnt, {nx, ny} });
					d[nx][ny][k] = cnt;
				}
				else if (list[nx][ny] == '#') {
					q.push({ -(cnt + 1), {nx,ny} });
					d[nx][ny][k] = cnt + 1;
				}
			}
		}
	}
}

void input() {
	cin >> N >> M;
	sq.push({ 0,0 });
	for (int i = 0; i < N + 2; i++) {
		for (int j = 0; j < M + 2; j++) {
			if (i == 0 || i == N + 1 || j == 0 || j == M + 1) list[i][j] = '.';
			else cin >> list[i][j];

			if (list[i][j] == '$') {
				sq.push({ i,j });
				list[i][j] = '.';
			}
		}
	}
}

void init() {
	while (!q.empty()) q.pop();
	while (!sq.empty()) sq.pop();
	memset(d, -1, sizeof(d));
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		init();
		input();
		bfs();
		func();
	}

	return 0;
}
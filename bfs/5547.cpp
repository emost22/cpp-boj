#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 103
#define LEN 6
using namespace std;
typedef pair<int, int> pi;

int list[MAX][MAX];
bool visit[MAX][MAX], sideChk[MAX][MAX];
int direct[2][6][2] = {
	{{-1,-1},{-1,0},{0,1},{1,0},{1,-1},{0,-1}},
	{{0,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0}}
};
int len[7];
int N, M, ans;

void sideBfs(int sx, int sy) {
	queue<pi> q;
	q.push({ sx,sy });
	sideChk[sx][sy] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		int idx = x % 2;
		for (int d = 0; d < 6; d++) {
			int nx = x + direct[idx][d][0];
			int ny = y + direct[idx][d][1];

			if (nx < 0 || ny < 0 || nx > N + 1 || ny > M + 1) continue;
			if (list[nx][ny] || sideChk[nx][ny]) continue;

			q.push({ nx,ny });
			sideChk[nx][ny] = true;
		}
	}
}

void bfs(int sx, int sy) {
	queue<pi> q;
	q.push({ sx,sy });
	visit[sx][sy] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		int cnt = 0;
		int idx = x % 2;
		for (int d = 0; d < 6; d++) {
			int nx = x + direct[idx][d][0];
			int ny = y + direct[idx][d][1];

			if (nx <= 0 || ny <= 0 || nx > N + 1 || ny > M + 1) continue;
			if (!list[nx][ny]) {
				if (!sideChk[nx][ny]) cnt++;
				continue;
			}
			cnt++;
			if (visit[nx][ny]) continue;

			q.push({ nx,ny });
			visit[nx][ny] = true;
		}

		ans += len[cnt];
	}
}

void func() {
	sideBfs(0, 0);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (!list[i][j] || visit[i][j]) continue;

			bfs(i, j);
		}
	}

	cout << ans << '\n';
}

void init() {
	for (int i = 0; i <= LEN; i++) {
		len[i] = LEN - i;
	}
}

void input() {
	cin >> M >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> list[i][j];
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	input();
	func();

	return 0;
}
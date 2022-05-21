#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#define MAX 5
using namespace std;
typedef pair<int, int> pi;

char list[MAX][MAX];
bool visit[MAX][MAX], chk[MAX][MAX];
int direct[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int sx, sy, ans;

int bfs() {
	queue<pi> q;
	q.push({ sx,sy });
	visit[sx][sy] = true;
	int cnt = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		cnt++;

		for (int i = 0; i < 4; i++) {
			int nx = x + direct[i][0];
			int ny = y + direct[i][1];

			if (nx < 0 || ny < 0 || nx >= MAX || ny >= MAX) continue;
			if (!chk[nx][ny] || visit[nx][ny]) continue;

			q.push({ nx,ny });
			visit[nx][ny] = true;
		}
	}

	return cnt == 7 ? 1 : 0;
}

void dfs(int x, int y, int cnt, int yCnt, bool f) {
	if (yCnt >= 4) return;
	if (cnt == 7) {
		memset(visit, false, sizeof(visit));
		ans += bfs();
		return;
	}

	int j = y;
	for (int i = x; i < MAX; i++) {
		for (; j < MAX; j++) {
			if (f) {
				sx = i;
				sy = j;
			}

			int nextYCnt = yCnt;
			chk[i][j] = true;
			if (list[i][j] == 'Y') nextYCnt++;
			if (j == MAX - 1) dfs(i + 1, 0, cnt + 1, nextYCnt, false);
			else dfs(i, j + 1, cnt + 1, nextYCnt, false);
			chk[i][j] = false;
		}
		j = 0;
	}
}

void func() {
	dfs(0, 0, 0, 0, true);
	cout << ans << '\n';
}

void input() {
	for (int i = 0; i < MAX; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
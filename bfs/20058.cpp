#include <iostream>
#include <queue>
#include <cstring>
#define MAX 64
using namespace std;
typedef pair<int, int> pi;

int list[MAX][MAX], tmp[MAX][MAX];
bool chk[MAX][MAX];
int direct[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int N, M, type, ans;

void swapArr(int x, int y, int s) {
	int xx = x;
	int yy = y + s - 1;
	for (int i = x; i < x + s; i++) {
		for (int j = y; j < y + s; j++) {
			tmp[xx][yy] = list[i][j];
			xx++;
		}
		xx = x;
		yy--;
	}

	for (int i = x; i < x + s; i++) {
		for (int j = y; j < y + s; j++) {
			list[i][j] = tmp[i][j];
		}
	}
}

void rotateArr() {
	for (int i = 0; i < N; i += type) {
		for (int j = 0; j < N; j += type) {
			swapArr(i, j, type);
		}
	}
}

void melting() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!list[i][j]) continue;

			int cnt = 0;
			for (int d = 0; d < 4; d++) {
				int nx = i + direct[d][0];
				int ny = j + direct[d][1];

				if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
				if (!list[nx][ny]) continue;

				cnt++;
			}

			if (cnt < 3) chk[i][j] = true;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (chk[i][j]) {
				list[i][j]--;
				chk[i][j] = false;
			}
		}
	}
}

int bfs(int sx, int sy) {
	queue<pi> q;
	q.push({ sx,sy });
	chk[sx][sy] = true;
	int cnt = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		ans += list[x][y];

		for (int i = 0; i < 4; i++) {
			int nx = x + direct[i][0];
			int ny = y + direct[i][1];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (!list[nx][ny] || chk[nx][ny]) continue;

			q.push({ nx,ny });
			chk[nx][ny] = true;
			cnt++;
		}
	}

	return cnt;
}

void func() {
	while (M--) {
		cin >> type;
		type = 1 << type;

		rotateArr();
		melting();
	}

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!list[i][j] || chk[i][j]) continue;

			int ret = bfs(i, j);
			cnt = max(cnt, ret);
		}
	}

	cout << ans << '\n' << cnt << '\n';
}

void input() {
	cin >> N >> M;
	N = 1 << N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
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
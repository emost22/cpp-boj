#include <iostream>
#include <algorithm>
using namespace std;

int list[501][501];
bool visit[501][501];
int direct[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int N, M, ans;

void dfs(int x, int y, int cnt, int sum) {
	if (cnt == 4) {
		ans = max(ans, sum);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + direct[i][0];
		int ny = y + direct[i][1];

		if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
		if (visit[nx][ny]) continue;

		visit[nx][ny] = true;
		dfs(nx, ny, cnt + 1, sum + list[nx][ny]);
		visit[nx][ny] = false;
	}
}

void func() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visit[i][j] = true;
			dfs(i, j, 1, list[i][j]);
			visit[i][j] = false;

			if (i + 2 < N && j + 1 < M) {
				ans = max(ans, list[i][j] + list[i + 1][j] + list[i + 2][j] + list[i + 1][j + 1]);
			}
			if (i + 1 < N && j - 1 >= 0 && j + 1 < M) {
				ans = max(ans, list[i][j] + list[i + 1][j - 1] + list[i + 1][j] + list[i + 1][j + 1]);
			}
			if (i + 1 < N && j + 2 < M) {
				ans = max(ans, list[i][j] + list[i][j + 1] + list[i][j + 2] + list[i + 1][j + 1]);
			}
			if (i - 1 >= 0 && i + 1 < N && j + 1 < M) {
				ans = max(ans, list[i][j] + list[i - 1][j + 1] + list[i][j + 1] + list[i + 1][j + 1]);
			}
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
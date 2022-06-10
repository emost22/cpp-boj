#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 1001
using namespace std;

int list[MAX][MAX], dp[MAX][MAX][2];
int direct[2][2][2] = { 
	{{0,1},{-1,0}},
	{{0,1},{1,0}}
};
int N, M;

int dfs(int x, int y, int flag) {
	if (x == N - 1 && y == M - 1 && flag) {
		return list[x][y];
	}

	int& ret = dp[x][y][flag];
	if (ret != -1e9) return ret;

	if (!flag) ret = dfs(x, y, !flag);
	for (int d = 0; d < 2; d++) {
		int nx = x + direct[flag][d][0];
		int ny = y + direct[flag][d][1];

		if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

		ret = max(ret, dfs(nx, ny, flag));
	}

	ret += list[x][y];
	return ret;
}

void func() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			for (int k = 0; k < 2; k++) {
				dp[i][j][k] = -1e9;
			}
		}
	}

	cout << dfs(N - 1, 0, 0) << '\n';
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
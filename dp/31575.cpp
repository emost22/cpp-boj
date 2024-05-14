#include <iostream>
#include <cstring>
#define MAX 301
using namespace std;

int dp[MAX][MAX];
int list[MAX][MAX];
int direct[2][2] = { {1,0},{0,1} };
int N, M;

int dfs(int x, int y) {
	if (x == N - 1 && y == M - 1) return 1;

	int& ret = dp[x][y];
	if (ret != -1) return ret;
	ret = 0;

	for (int d = 0; d < 2; d++) {
		int nx = x + direct[d][0];
		int ny = y + direct[d][1];

		if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
		if (!list[nx][ny]) continue;

		if (dfs(nx, ny)) ret = 1;
	}

	return ret;
}

void func() {
	memset(dp, -1, sizeof(dp));
	if (dfs(0, 0)) cout << "Yes\n";
	else cout << "No\n";
}

void input() {
	cin >> M >> N;
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
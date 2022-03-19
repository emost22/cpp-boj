#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 1001
using namespace std;

int list[MAX][MAX];
int dp[MAX][MAX][4];
int direct[4][2] = { {0,0},{1,-1},{1,0},{1,1} };
int N, M;

int dfs(int x, int y, int d) {
	if (x == N) return list[x][y];

	int &ret = dp[x][y][d];
	if (ret != -1) return ret;
	ret = 1e9;

	for (int i = 1; i <= 3; i++) {
		if (d == i) continue;

		int nx = x + direct[i][0];
		int ny = y + direct[i][1];

		if (nx < 1 || ny < 1 || nx > N || ny > M) continue;
		ret = min(ret, dfs(nx, ny, i) + list[x][y]);
	}

	return ret;
}

void func() {
	memset(dp, -1, sizeof(dp));
	int ans = 1e9;
	for (int i = 1; i <= M; i++) {
		ans = min(ans, dfs(1, i, 0));
	}

	cout << ans << '\n';
}

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
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
#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 1001
#define MOD 1000000007
using namespace std;

int dp[MAX][MAX];
bool chk[MAX][MAX];
int direct[2][3][2] = {
	{{1,0},{1,1},{0,1}},
	{{1,-1},{1,0},{0,1}}
};
int N, M, K;

int dfs(int x, int y) {
	if (x == N && y == M) return 1;

	int& ret = dp[x][y];
	if (ret != -1) return ret;
	ret = 0;

	int idx = x % 2;
	for (int d = 0; d < 3; d++) {
		int nx = x + direct[idx][d][0];
		int ny = y + direct[idx][d][1];

		if (nx <= 0 || ny <= 0 || nx > N || ny > M) continue;
		if (chk[nx][ny]) continue;

		ret = (ret + dfs(nx, ny)) % MOD;
	}

	return ret;
}

void func() {
	memset(dp, -1, sizeof(dp));
	cout << dfs(1, 1) << '\n';
}

void input() {
	int x, y;
	cin >> M >> N >> K;
	while (K--) {
		cin >> y >> x;
		chk[x][y] = true;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
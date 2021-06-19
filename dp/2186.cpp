#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string str;
char list[110][110];
int dp[100][100][81];
int direct[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int N, M, K, strLength;

int dfs(int x, int y, int idx) {
	if (idx == strLength) return 1;

	int &ret = dp[x][y][idx];
	if (ret != -1) return ret;
	ret = 0;

	for (int i = 0; i < 4; i++) {
		for (int j = 1; j <= K; j++) {
			int nx = x + direct[i][0] * j;
			int ny = y + direct[i][1] * j;

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (list[nx][ny] != str[idx]) continue;

			ret += dfs(nx, ny, idx + 1);
		}
	}

	return ret;
}

void func() {
	int ans = 0;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (list[i][j] != str[0]) continue;

			ans += dfs(i, j, 1);
		}
	}

	cout << ans << '\n';
}

void input() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> list[i][j];
		}
	}
	cin >> str;
	strLength = str.size();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
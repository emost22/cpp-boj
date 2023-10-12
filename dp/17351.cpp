#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 501
using namespace std;

char ch[] = "MOLA";
char list[MAX][MAX];
int dp[MAX][MAX][4];
int direct[2][2] = { {0,1},{1,0} };
int N;

int dfs(int x, int y, int len) {
	if (x == N && y == N) return 0;

	int& ret = dp[x][y][len];
	if (ret != -1) return ret;
	ret = 0;

	for (int d = 0; d < 2; d++) {
		int nx = x + direct[d][0];
		int ny = y + direct[d][1];

		if (nx > N || ny > N) continue;

		if (list[nx][ny] == 'M') {
			ret = max(ret, dfs(nx, ny, 1));
		}
		else if (list[nx][ny] != ch[len]) {
			ret = max(ret, dfs(nx, ny, 0));
		}
		else if (len == 3) {
			ret = max(ret, dfs(nx, ny, 0) + 1);
		}
		else {
			ret = max(ret, dfs(nx, ny, len + 1));
		}
	}

	return ret;
}

void func() {
	memset(dp, -1, sizeof(dp));

	if (list[1][1] == 'M') cout << dfs(1, 1, 1) << '\n';
	else cout << dfs(1, 1, 0) << '\n';
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
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
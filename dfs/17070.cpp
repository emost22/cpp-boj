#include <iostream>
#include <cstring>
using namespace std;

int list[17][17], dp[17][17][17][17];
int N, ans;

int dfs(int fx, int fy, int sx, int sy) {
	if (sx > N || sy > N) return 0;
	if (sx == N && sy == N) return 1;
	if (dp[fx][fy][sx][sy] != -1) return dp[fx][fy][sx][sy];
	dp[fx][fy][sx][sy] = 0;

	if (fx == sx && fy + 1 == sy) { //가로
		if (!list[sx][sy + 1]) {
			dp[fx][fy][sx][sy] += dfs(sx, sy, sx, sy + 1);

			if (!list[sx + 1][sy + 1] && !list[sx + 1][sy]) {
				dp[fx][fy][sx][sy] += dfs(sx, sy, sx + 1, sy + 1);
			}
		}
	}
	else if (fy == sy && fx + 1 == sx) { //세로
		if (!list[sx + 1][sy]) {
			dp[fx][fy][sx][sy] += dfs(sx, sy, sx + 1, sy);

			if (!list[sx + 1][sy + 1] && !list[sx][sy + 1]) {
				dp[fx][fy][sx][sy] += dfs(sx, sy, sx + 1, sy + 1);
			}
		}
	}
	else { //대각
		if (!list[sx + 1][sy]) {
			dp[fx][fy][sx][sy] += dfs(sx, sy, sx + 1, sy);
		}
		if (!list[sx][sy + 1]) {
			dp[fx][fy][sx][sy] += dfs(sx, sy, sx, sy + 1);
		}
		if (!list[sx + 1][sy] && !list[sx][sy + 1] && !list[sx + 1][sy + 1]) {
			dp[fx][fy][sx][sy] += dfs(sx, sy, sx + 1, sy + 1);
		}
	}

	return dp[fx][fy][sx][sy];
}

void input() {
	memset(dp, -1, sizeof(dp));
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
	cout << dfs(1, 1, 1, 2) << '\n';

	return 0;
}
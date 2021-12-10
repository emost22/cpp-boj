#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 10001
using namespace std;

int list[2][MAX], dp[3][MAX];
int N, W;

void solve() {
	for (int i = 2; i <= N; i++) {
		int u = (list[0][i - 1] + list[0][i] <= W) ? 1 : 2;
		int d = (list[1][i - 1] + list[1][i] <= W) ? 1 : 2;
		int a = (list[0][i] + list[1][i] <= W) ? 1 : 2;

		dp[0][i] = min(dp[1][i - 1] + u, dp[2][i - 1] + 1);
		dp[1][i] = min(dp[0][i - 1] + d, dp[2][i - 1] + 1);
		dp[2][i] = min({ dp[2][i - 1] + a, dp[2][i - 2] + u + d, dp[0][i] + 1, dp[1][i] + 1 });
	}
}

void func() {
	if (N == 1) {
		cout << (list[0][1] + list[1][1] <= W ? 1 : 2) << '\n';
		return;
	}

	int ans = 1e9;
	int tmpu = list[1][1];
	int tmpd = list[0][1];
	memset(dp, 0, sizeof(dp));
	dp[0][1] = 1;
	dp[1][1] = 1;
	dp[2][1] = (list[0][1] + list[1][1] <= W) ? 1 : 2;
	solve();
	ans = min(ans, dp[2][N]);

	if (list[0][1] + list[0][N] <= W) {
		dp[0][1] = 1;
		dp[1][1] = 1;
		dp[2][1] = 2;
		list[0][1] = 1e9;

		solve();
		ans = min(ans, dp[1][N]);
		list[0][1] = tmpd;
	}

	if (list[1][1] + list[1][N] <= W) {
		dp[0][1] = 1;
		dp[1][1] = 1;
		dp[2][1] = 2;
		list[1][1] = 1e9;

		solve();
		ans = min(ans, dp[0][N]);
		list[1][1] = tmpu;
	}

	if (list[0][1] + list[0][N] <= W && list[1][1] + list[1][N] <= W) {
		dp[0][1] = 1;
		dp[1][1] = 1;
		dp[2][1] = 2;
		list[0][1] = 1e9;
		list[1][1] = 1e9;

		solve();
		ans = min(ans, dp[2][N - 1]);
		list[0][1] = tmpd;
		list[1][1] = tmpu;
	}

	cout << ans << '\n';
}

void input() {
	cin >> N >> W;
	for (int i = 0; i < 2; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> list[i][j];
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
	}

	return 0;
}
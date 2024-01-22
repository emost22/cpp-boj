#include <iostream>
#include <cstring>
#define MAX 1002
using namespace std;

int list[MAX][MAX], dp[MAX][MAX];
int N, M;

void func() {
	memset(dp, 0, sizeof(dp));
	int sx, sy, ex, ey, diff;
	while (M--) {
		cin >> sx >> sy >> ex >> ey >> diff;
		dp[sx][sy] += diff;
		dp[ex + 1][ey + 1] += diff;
		dp[sx][ey + 1] -= diff;
		dp[ex + 1][sy] -= diff;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			dp[i][j] = dp[i][j] + dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			dp[i][j] = dp[i][j] + dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + list[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << dp[i][N] - dp[i - 1][N] << ' ';
	}
	cout << '\n';

	for (int i = 1; i <= N; i++) {
		cout << dp[N][i] - dp[N][i - 1] << ' ';
	}
	cout << '\n';
}

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
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
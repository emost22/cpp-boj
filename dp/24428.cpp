#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;

int dp[MAX][MAX][4];
int list[MAX][MAX];
bool chk[MAX][MAX];
int N, M;

void func() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (chk[i][j]) {
				for (int k = 1; k <= 3; k++) {
					if (!dp[i - 1][j][k - 1] && !dp[i][j - 1][k - 1]) continue;

					dp[i][j][k] = max(dp[i][j][k], max(dp[i - 1][j][k - 1], dp[i][j - 1][k - 1]) + list[i][j]);
					if (k == 3) {
						dp[i][j][k] = max(dp[i][j][k], max(dp[i - 1][j][k], dp[i][j - 1][k]) + list[i][j]);
					}
				}
			}
			else {
				dp[i][j][0] = max(dp[i - 1][j][0], dp[i][j - 1][0]) + list[i][j];
				for (int k = 1; k <= 3; k++) {
					if (!dp[i - 1][j][k] && !dp[i][j - 1][k]) continue;

					dp[i][j][k] = max(dp[i][j][k], max(dp[i - 1][j][k], dp[i][j - 1][k]) + list[i][j]);
				}
			}
		}
	}
	if (!dp[N][N][3]) dp[N][N][3] = -1;

	cout << dp[N][N][3] << '\n';
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> list[i][j];
		}
	}

	int x, y;
	cin >> M;
	while (M--) {
		cin >> x >> y;
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
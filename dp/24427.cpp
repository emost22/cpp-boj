#include <iostream>
#include <cstring>
#define MAX 1001
using namespace std;

int dp[MAX][MAX][2];
int list[MAX][MAX];
int chk[MAX][MAX];
int N, M;

void func() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (chk[i][j]) {
				dp[i][j][1] = max(max(dp[i - 1][j][1], dp[i][j - 1][1]), max(dp[i - 1][j][0], dp[i][j - 1][0])) + list[i][j];
			}
			else {
				dp[i][j][0] = max(dp[i - 1][j][0], dp[i][j - 1][0]) + list[i][j];
				if (max(dp[i - 1][j][1], dp[i][j - 1][1])) {
					dp[i][j][1] = max(dp[i - 1][j][1], dp[i][j - 1][1]) + list[i][j];
				}
			}
		}
	}

	cout << dp[N][N][1] << '\n';
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
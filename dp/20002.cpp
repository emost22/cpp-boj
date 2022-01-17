#include <iostream>
#include <algorithm>
#define MAX 301
using namespace std;

int dp[MAX][MAX];
int N;

void func() {
	int ans = -1e9;
	for (int k = 0; k < N; k++) {
		for (int i = 1; i <= N - k; i++) {
			for (int j = 1; j <= N - k; j++) {
				int nx = i + k;
				int ny = j + k;

				ans = max(ans, dp[nx][ny] - dp[i - 1][ny] - dp[nx][j - 1] + dp[i - 1][j - 1]);
			}
		}
	}

	cout << ans << '\n';
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> dp[i][j];

			dp[i][j] = dp[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
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
#include <iostream>
#include <algorithm>
using namespace std;

int dp[21][201];
int N, M;

void input() {
	int d, x;
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> d >> x;
		for (int j = 1; j <= N; j++) {
			dp[i][j] = dp[i - 1][j];
			if (d > j) continue;

			dp[i][j] = max(dp[i][j], dp[i - 1][j - d] + x);
		}
	}

	cout << dp[M][N] << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}
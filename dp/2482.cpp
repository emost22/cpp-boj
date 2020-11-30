#include <iostream>
#define MOD 1000000003
using namespace std;

int dp[1001][1001], N, K;

void func() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K && j <= i / 2; j++) {
			if (j == 1) dp[i][j] = i;
			else if (i % 2 == 0 && j == i / 2) {
				dp[i][j] = 2;
			}
			else dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % MOD;
		}
	}

	cout << dp[N][K] % MOD << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> K;
	func();

	return 0;
}
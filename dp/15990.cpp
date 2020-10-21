#include <iostream>
#define MOD 1000000009
using namespace std;

int dp[3][100001];

void init() {
	dp[0][1] = 1;
	dp[1][2] = 1;
	dp[0][3] = 1;
	dp[1][3] = 1;
	dp[2][3] = 1;
	for (int i = 4; i <= 100000; i++) {
		dp[0][i] = (dp[1][i - 1] + dp[2][i - 1]) % MOD;
		dp[1][i] = (dp[0][i - 2] + dp[2][i - 2]) % MOD;
		dp[2][i] = (dp[0][i - 3] + dp[1][i - 3]) % MOD;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	int tc, N;
	cin >> tc;
	while (tc--) {
		cin >> N;
		cout << ((dp[0][N] + dp[1][N]) % MOD + dp[2][N]) % MOD << '\n';
	}

	return 0;
}
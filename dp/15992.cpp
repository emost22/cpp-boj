#include <iostream>
#define MOD 1000000009
using namespace std;

int dp[1001][1001];

void init() {
	dp[1][1] = 1;
	dp[2][1] = 1;
	dp[2][2] = 1;
	dp[3][1] = 1;
	dp[3][2] = 2;
	dp[3][3] = 1;
	for (int i = 4; i <= 1000; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i][j] = ((dp[i - 1][j - 1] + dp[i - 2][j - 1]) % MOD + dp[i - 3][j - 1]) % MOD;
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	int tc, N, M;
	cin >> tc;
	while (tc--) {
		cin >> N >> M;
		cout << dp[N][M] << '\n';
	}

	return 0;
}
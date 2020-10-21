#include <iostream>
#define MOD 1000000009
using namespace std;

int dp[100001];

void init() {
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 2;
	dp[4] = 3;
	dp[5] = 3;
	for (int i = 6; i <= 100000; i++) {
		dp[i] = ((dp[i - 2] + dp[i - 4]) % MOD + dp[i - 6]) % MOD;
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
		cout << dp[N] << '\n';
	}

	return 0;
}
#include <iostream>
#define MOD 1000000009
using namespace std;

int dp[1000001];

void func() {
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i <= 1000000; i++) {
		dp[i] = ((dp[i - 1] + dp[i - 2]) % MOD + dp[i - 3]) % MOD;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	func();
	int tc, x;
	cin >> tc;
	while (tc--) {
		cin >> x;
		cout << dp[x] << '\n';
	}

	return 0;
}
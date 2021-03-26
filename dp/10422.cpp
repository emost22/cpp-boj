#include <iostream>
#define MOD 1000000007
using namespace std;
typedef long long ll;

ll dp[2501];
int L;

void init() {
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= 2500; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] += ((dp[j - 1] * dp[i - j]) % MOD);
			dp[i] %= MOD;
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> L;
		if (L % 2) cout << "0\n";
		else cout << dp[L / 2] << '\n';
	}

	return 0;
}
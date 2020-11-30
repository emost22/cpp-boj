#include <iostream>
using namespace std;
typedef long long ll;

ll dp[65][10], sum[65];

void init() {
	for (int i = 0; i <= 9; i++) {
		dp[1][i] = 1;
		sum[1] += 1;
	}

	for (int i = 2; i <= 64; i++) {
		dp[i][0] = sum[i - 1];
		sum[i] += sum[i - 1];
		for (int j = 1; j <= 9; j++) {
			dp[i][j] = dp[i][j - 1] - dp[i - 1][j - 1];
			sum[i] += dp[i][j];
		}
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
		cout << sum[N] << '\n';
	}

	return 0;
}
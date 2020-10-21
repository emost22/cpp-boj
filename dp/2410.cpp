#include <iostream>
#define mod 1000000000
using namespace std;

int dp[1000001];

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= N; i++) {
		dp[i] = (dp[i / 2] + dp[i - 2]) % mod;
	}

	cout << dp[N] << '\n';

	return 0;
}
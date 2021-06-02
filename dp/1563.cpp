#include <iostream>
#define MOD 1000000
using namespace std;

int dp[1001][3];
int N;

void init() {
	dp[0][1] = 1;
	dp[1][0] = 1;
	dp[1][1] = 1;
	dp[1][2] = 1;
	dp[2][0] = 3;
	dp[2][1] = 2;
	dp[2][2] = 3;
	for (int i = 3; i <= 1000; i++) {
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % MOD;
		dp[i][1] = (dp[i - 1][1] + dp[i - 2][1] + dp[i - 3][1]) % MOD;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 2][0] + dp[i - 2][1]) % MOD;
	}
}

void input() {
	cin >> N;
	cout << (dp[N][0] + dp[N][1] + dp[N][2]) % MOD << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	input();

	return 0;
}
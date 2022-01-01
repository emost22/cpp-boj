#include <iostream>
#define MAX 1516
#define MOD 1000000007
using namespace std;

int dp[MAX][3];
int N;

void init() {
	dp[2][0] = 1;
	dp[2][1] = 1;
	for (int i = 3; i < MAX; i++) {
		dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % MOD;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
	}
}

void input() {
	cin >> N;
	cout << dp[N][0] << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	input();

	return 0;
}
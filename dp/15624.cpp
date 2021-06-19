#include <iostream>
#define MOD 1000000007
using namespace std;

int dp[1000001];
int N;

void init() {
	dp[1] = 1;
	for (int i = 2; i <= 1000000; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
	}
}

void input() {
	cin >> N;
	cout << dp[N] << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	input();

	return 0;
}
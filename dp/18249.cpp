#include <iostream>
#define MAX 191230
#define MOD 1000000007
using namespace std;

int dp[MAX];
int N;

void init() {
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i < MAX; i++) {
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

	int tc;
	cin >> tc;
	while (tc--) {
		input();
	}

	return 0;
}
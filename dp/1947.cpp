#include <iostream>
#define MOD 1000000000
using namespace std;
typedef long long ll;

ll dp[1000001];
int N;

void init() {
	dp[1] = 0;
	dp[2] = 1;
	for (int i = 3; i <= 1000000; i++) {
		dp[i] = ((i - 1) * (dp[i - 1] + dp[i - 2])) % MOD;
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
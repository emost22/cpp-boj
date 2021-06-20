#include <iostream>
#define MOD 987654321
using namespace std;
typedef long long ll;

ll dp[10001];
int N;

void init() {
	dp[0] = 1;
	dp[2] = 1;
	for (int i = 4; i <= 10000; i += 2) {
		for (int j = 0; j <= i - 2; j += 2) {
			dp[i] = (dp[i] + dp[j] * dp[i - 2 - j]) % MOD;
		}
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
#include <iostream>
#define MOD 1000000009
using namespace std;
typedef long long ll;

ll dp[33334];
int N;

void init() {
	dp[2] = 2;
	for (int i = 3; i <= 33333; i++) {
		dp[i] = (dp[i - 1] * 3) % MOD;
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
#include <iostream>
using namespace std;
typedef long long ll;

ll dp[117];
int N;

void init() {
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	for (int i = 4; i <= 116; i++) {
		dp[i] = dp[i - 1] + dp[i - 3];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	cin >> N;
	cout << dp[N] << '\n';

	return 0;
}
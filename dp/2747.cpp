#include <iostream>
using namespace std;

int dp[46];
int N;

void init() {
	dp[1] = 1;
	for (int i = 2; i <= 45; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
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
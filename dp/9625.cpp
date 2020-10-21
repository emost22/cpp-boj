#include <iostream>
using namespace std;

int dp[46];

void func(int N) {
	dp[1] = 1;
	for (int i = 2; i <= N; i++) {
		dp[i] = dp[i - 2] + dp[i - 1];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	func(N);
	cout << dp[N - 1] << ' ' << dp[N] << '\n';

	return 0;
}
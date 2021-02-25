#include <iostream>
#include <algorithm>
using namespace std;

int dp[100001];
int N;

void func() {
	dp[1] = -1;
	dp[2] = 1;
	dp[3] = -1;
	dp[4] = 2;
	dp[5] = 1;
	for (int i = 6; i <= N; i++) {
		if (dp[i - 5] == -1 && dp[i - 2] == -1) dp[i] = -1;
		else if (dp[i - 5] == -1) dp[i] = dp[i - 2] + 1;
		else if (dp[i - 2] == -1) dp[i] = dp[i - 5] + 1;
		else dp[i] = min(dp[i - 2], dp[i - 5]) + 1;
	}

	cout << dp[N] << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	func();

	return 0;
}
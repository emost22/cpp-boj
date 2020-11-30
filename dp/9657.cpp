#include <iostream>
using namespace std;

int dp[1001], N;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	dp[1] = 1;
	dp[3] = 1;
	dp[4] = 1;
	for (int i = 5; i <= N; i++) {
		if (dp[i - 1] && dp[i - 3] && dp[i - 4]) continue;
		else dp[i] = 1;
	}

	if (dp[N]) cout << "SK\n";
	else cout << "CY\n";

	return 0;
}
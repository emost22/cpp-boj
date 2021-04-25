#include <iostream>
#include <algorithm>
using namespace std;

int dp[2][3], N;

void input() {
	int t = 1;
	cin >> dp[0][0] >> dp[0][1] >> dp[0][2];
	dp[0][0] = 10000;
	dp[0][2] += dp[0][1];
	for (int i = 2; i <= N; i++, t = 1 - t) {
		cin >> dp[t][0] >> dp[t][1] >> dp[t][2];
		dp[t][0] += min(dp[1 - t][0], dp[1 - t][1]);
		dp[t][1] += min(min(dp[t][0], dp[1 - t][0]), min(dp[1 - t][1], dp[1 - t][2]));
		dp[t][2] += min(dp[t][1], min(dp[1 - t][1], dp[1 - t][2]));
	}
	cout << dp[1 - t][1] << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	for (int t = 1; ; t++) {
		cin >> N;
		if (!N) return 0;
		cout << t << ". ";
		input();
	}
}
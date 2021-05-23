#include <iostream>
#include <algorithm>
using namespace std;

int dp[101][10001];
int N, T;

void input() {
	int t, s;
	cin >> N >> T;
	for (int i = 1; i <= N; i++) {
		cin >> t >> s;
		for (int j = 1; j <= T; j++) {
			if (t > j) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - t] + s);
		}
	}

	cout << dp[N][T] << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}
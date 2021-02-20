#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001][1001];
int N, M, ans;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	char ch;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> ch;
			dp[i][j] = ch - '0';
			if (dp[i][j]) dp[i][j] += min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
			ans = max(ans, dp[i][j]);
		}
	}

	cout << ans * ans << '\n';

	return 0;
}
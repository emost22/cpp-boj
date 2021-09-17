#include <iostream>
#include <algorithm>
using namespace std;

int list[1001][1001], dp[1001][1001];
int N, M, ans;

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> list[i][j];
			if (!list[i][j]) {
				dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
			}
			ans = max(ans, dp[i][j]);
		}
	}

	cout << ans << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}
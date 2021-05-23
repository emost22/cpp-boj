#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001][10001];
int N, M;

void input() {
	int t, s;
	cin >> M >> N;
	for (int i = 1; i <= N; i++) {
		cin >> s >> t;
		for (int j = 1; j <= M; j++) {
			if (j < t) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - t] + s);
		}
	}

	cout << dp[N][M] << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}
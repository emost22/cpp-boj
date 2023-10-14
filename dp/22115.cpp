#include <iostream>
#define MAX_N 101
#define MAX_M 100001
using namespace std;

int dp[MAX_N][MAX_M], list[MAX_N];
int N, M;

void func() {
	fill(dp[0] + 1, dp[0] + M + 1, 1e9);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (j < list[i]) {
				dp[i][j] = dp[i - 1][j];
				continue;
			}
			dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - list[i]] + 1);
		}
	}

	if (dp[N][M] == 1e9) cout << "-1\n";
	else cout << dp[N][M] << '\n';
}

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
#include <iostream>
using namespace std;

pair<int, int> list[101];
int dp[101][10001];
int N, T;

void func() {
	for (int i = 0; i <= N; i++) {
		dp[i][0] = 1;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= T; j++) {
			dp[i][j] = dp[i - 1][j];

			for (int k = 1; k <= list[i].second; k++) {
				if (j < list[i].first * k) break;
				dp[i][j] += dp[i - 1][j - list[i].first*k];
			}
		}
	}

	cout << dp[N][T] << '\n';
}

void input() {
	cin >> T >> N;
	for (int i = 1; i <= N; i++) {
		cin >> list[i].first >> list[i].second;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
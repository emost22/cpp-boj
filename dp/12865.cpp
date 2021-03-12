#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> list[101];
int dp[101][100001];
int N, K;

void func() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			dp[i][j] = dp[i - 1][j];
			if (list[i].first > j) continue;

			dp[i][j] = max(dp[i][j], dp[i - 1][j - list[i].first] + list[i].second);
		}
	}

	cout << dp[N][K] << '\n';
}

void input() {
	cin >> N >> K;
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
#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;

int dp[MAX * 2];
int N, K;

void func() {
	for (int i = 1; i <= N * 2; i++) {
		dp[i] += dp[i - 1];
	}

	int ans = 0;
	for (int i = 0; i < N; i++) {
		ans = max(ans, dp[i + K] - dp[i]);
	}

	cout << ans << '\n';
}

void input() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> dp[i];
		dp[N + i] = dp[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
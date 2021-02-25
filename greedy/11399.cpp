#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001];
int N;

void func() {
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		dp[i] += dp[i - 1];
		ans += dp[i];
	}

	cout << ans << '\n';
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> dp[i];
	}
	sort(dp + 1, dp + 1 + N);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
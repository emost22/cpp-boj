#include <iostream>
#include <algorithm>
#define MAX 1000001
using namespace std;
typedef long long ll;

ll dp[MAX];
int N, K;

void func() {
	for (int i = 1; i < MAX; i++) {
		dp[i] += dp[i - 1];
	}

	if (K >= MAX / 2) {
		cout << dp[MAX - 1] << '\n';
		return;
	}

	ll ans = dp[K];
	for (int i = K + 1; i < MAX - K; i++) {
		ans = max(ans, dp[i + K] - dp[i - K - 1]);
	}

	cout << ans << '\n';
}

void input() {
	int idx;
	ll x;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> x >> idx;
		dp[idx] = x;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
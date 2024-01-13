#include <iostream>
#include <algorithm>
using namespace std;

int dp[10001], list[100], cost[100], N, M, ans;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> cost[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 10000; j >= cost[i]; j--) {
			dp[j] = max(dp[j], dp[j - cost[i]] + list[i]);
		}
	}

	for (int i = 0; i <= 10000; i++) {
		if (dp[i] >= M) {
			ans = i;
			break;
		}
	}
	cout << ans << '\n';

	return 0;
}
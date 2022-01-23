#include <iostream>
#include <algorithm>
#define MAX 250001
using namespace std;

int dp[MAX];
int N;

void input() {
	int ans = -1e9;
	for (int i = 1; i <= N; i++) {
		cin >> dp[i];
		dp[i] = max(dp[i - 1] + dp[i], dp[i]);
		ans = max(ans, dp[i]);
	}

	cout << ans << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (cin >> N) {
		if (!N) return 0;

		input();
	}
}
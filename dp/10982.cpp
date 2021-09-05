#include <iostream>
#include <algorithm>
#define INF 1000000000
using namespace std;

int A[1001], B[1001];
int dp[2][100001];
int N, sum;

void init() {
	for (int i = 0; i <= 100000; i++) {
		dp[0][i] = INF;
		dp[1][i] = INF;
	}
	dp[1][sum] = 0;
	dp[1][sum - A[1]] = B[1];
}

void func() {
	init();

	int t = 0;
	for (int i = 2; i <= N; i++) {

		fill(dp[t], dp[t] + sum + 1, INF);
		for (int j = 0; j <= sum; j++) {
			if (dp[1 - t][j] == INF) continue;
			dp[t][j] = dp[1 - t][j];
			dp[t][j - A[i]] = min(dp[t][j - A[i]], dp[1 - t][j] + B[i]);
		}

		t = 1 - t;
	}

	int ans = INF;
	for (int i = 0; i <= 100000; i++) {
		ans = min(ans, max(i, dp[1 - t][i]));
	}

	cout << ans << '\n';
	sum = 0;
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i] >> B[i];
		sum += A[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
	}
	return 0;
}
#include <iostream>
#include <cstring>
using namespace std;

int dp[10001];
int N, M;

void input() {
	int x;
	cin >> N;
	dp[0] = 1;
	for (int i = 0; i < N; i++) {
		cin >> x;
		for (int j = x; j <= 10000; j++) {
			dp[j] += dp[j - x];
		}
	}
	cin >> M;
	cout << dp[M] << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		memset(dp, 0, sizeof(dp));
	}

	return 0;
}
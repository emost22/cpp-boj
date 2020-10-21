#include <iostream>
#define mod 1000000007
using namespace std;

long long dp[101][101][101];

long long find(int N, int L, int R) {
	dp[1][1][1] = 1;
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				dp[i][j][k] = (dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1] + dp[i - 1][j][k] * (i - 2)) % mod;
			}
		}
	}

	return dp[N][L][R];
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, L, R;
	cin >> N >> L >> R;
	cout << find(N, L, R) << '\n';

	return 0;
}
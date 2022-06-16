#include <iostream>
#define MAX 1001
#define MOD 1000000007
using namespace std;

int dp[MAX][MAX];

void init() {
	for (int i = 0; i < MAX; i++) {
		dp[i][0] = 1;
		dp[i][i] = 1;
		for (int j = 1; j < i; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
		}
	}
}

void input() {
	int N, M;
	cin >> N >> M;
	cout << dp[N][M] << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();

	int tc;
	cin >> tc;
	while (tc--) {
		input();
	}

	return 0;
}
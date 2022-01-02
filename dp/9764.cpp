#include <iostream>
#define MAX 2001
#define MOD 100999
using namespace std;

int dp[MAX][MAX];

void init() {
	for (int i = 0; i < MAX; i++) {
		dp[0][i] = 1;
	}
	
	for (int i = 1; i < MAX; i++) {
		for (int j = 1; j < MAX; j++) {
			if (i < j) {
				dp[i][j] = dp[i][j - 1];
			}
			else {
				dp[i][j] = (dp[i][j - 1] + dp[i - j][j - 1]) % MOD;
			}
		}
	}
}

void input() {
	int N;
	cin >> N;
	cout << dp[N][N] << '\n';
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
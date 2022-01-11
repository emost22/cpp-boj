#include <iostream>
#define MAX 5001
#define MOD 1000000000
using namespace std;

int dp[MAX][MAX];
int N, M;

void init() {
	dp[0][1] = 1;
	for (int i = 1; i < MAX; i++) {
		dp[1][i] = i;
	}

	for (int i = 2; i < MAX; i++) {
		for (int j = 1; j < MAX; j++) {
			dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % MOD;
		}
	}
}

void input() {
	cin >> N >> M;
	cout << dp[N][M] << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	input();

	return 0;
}
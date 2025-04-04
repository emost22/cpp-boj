#include <iostream>
#define MAX 53
#define MOD 10007
using namespace std;

int dp[MAX][MAX];
int N;

void init() {
	for (int i = 0; i < MAX; i++) {
		dp[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
		}
	}
}

void func() {
	init();

	int ret = 0;
	for (int i = 1; i <= (N >> 2); i++) {
		if (i & 1) ret = (ret + (dp[13][i] * dp[52 - (i << 2)][N - (i << 2)])) % MOD;
		else ret = (ret + MOD - (dp[13][i] * dp[52 - (i << 2)][N - (i << 2)]) % MOD) % MOD;
	}
	cout << ret << '\n';
}

void input() {
	cin >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
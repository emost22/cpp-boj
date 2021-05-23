#include <iostream>
#define MOD 1000000007
using namespace std;

int dp[1001][1001];
int N, M;

void func() {
	dp[0][0] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			dp[i][j] = ((dp[i - 1][j - 1] + dp[i - 1][j]) % MOD + dp[i][j - 1]) % MOD;
		}
	}
	
	cout << dp[N][M] << '\n';
}

void input() {
	cin >> N >> M;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
#include <iostream>
#define MAX 201
#define MOD 1000007
using namespace std;

int dp[MAX][MAX];
int N, M, mx, my;

void func() {
	dp[1][1] = 1;
	for (int i = 1; i <= mx; i++) {
		for (int j = 1; j <= my; j++) {
			if (i == 1 && j == 1) continue;
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
		}
	}

	for (int i = mx; i <= N; i++) {
		for (int j = my; j <= M; j++) {
			if (i == mx && j == my) continue;
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
		}
	}

	cout << dp[N][M] << '\n';
}

void input() {
	cin >> N >> M >> mx >> my;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	input();
	func();

	return 0;
}
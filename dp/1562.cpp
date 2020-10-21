#include <iostream>
#include <cstring>
#define MOD 1000000000
using namespace std;

int dp[10][101][1 << 10];
int N, ans;

int func(int v, int idx, int x) {
	if (idx == N) {
		return x == (1 << 10) - 1 ? 1 : 0;
	}

	if (dp[v][idx][x] != -1) return dp[v][idx][x];
	dp[v][idx][x] = 0;

	if (v - 1 >= 0) {
		dp[v][idx][x] = (dp[v][idx][x] + func(v - 1, idx + 1, x | (1 << (v - 1)))) % MOD;
	}

	if (v + 1 <= 9) {
		dp[v][idx][x] = (dp[v][idx][x] + func(v + 1, idx + 1, x | (1 << (v + 1)))) % MOD;
	}

	return dp[v][idx][x];
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= 9; i++) {
		memset(dp, -1, sizeof(dp));
		ans += func(i, 1, 1 << i);
		ans %= MOD;
	}
	cout << ans << '\n';

	return 0;
}
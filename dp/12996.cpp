#include <iostream>
#include <cstring>
#define MAX 51
#define MOD 1000000007
using namespace std;

int dp[MAX][MAX][MAX][MAX];
int N, x, y, z;

int solve(int n, int a, int b, int c) {
	if (!n) {
		return !a && !b && !c;
	}
	
	int& ret = dp[n][a][b][c];
	if (ret != -1) return ret;
	ret = 0;

	if (a && b && c) {
		ret = (ret + solve(n - 1, a - 1, b - 1, c - 1)) % MOD;
	}

	if (a && b) {
		ret = (ret + solve(n - 1, a - 1, b - 1, c)) % MOD;
	}
	if (a && c) {
		ret = (ret + solve(n - 1, a - 1, b, c - 1)) % MOD;
	}
	if (b && c) {
		ret = (ret + solve(n - 1, a, b - 1, c - 1)) % MOD;
	}

	if (a) {
		ret = (ret + solve(n - 1, a - 1, b, c)) % MOD;
	}
	if (b) {
		ret = (ret + solve(n - 1, a, b - 1, c)) % MOD;
	}
	if (c) {
		ret = (ret + solve(n - 1, a, b, c - 1)) % MOD;
	}

	return ret;
}

void func() {
	memset(dp, -1, sizeof(dp));
	cout << solve(N, x, y, z) << '\n';
}

void input() {
	cin >> N >> x >> y >> z;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
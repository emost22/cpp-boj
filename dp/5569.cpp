#include <iostream>
#include <cstring>
#define mod 100000
using namespace std;

int w, h;
int dp[101][101][2][2], ans;

int func(int x, int y, int chk, int turn) {
	if (x == w && y == h) {
		return 1;
	}

	if (dp[x][y][chk][turn] != -1) return dp[x][y][chk][turn];
	dp[x][y][chk][turn] = 0;

	if (chk) {
		if (turn) {
			if (y + 1 <= h) dp[x][y][chk][turn] = (dp[x][y][chk][turn] + func(x, y + 1, 0, turn)) % mod;
		}
		else {
			if (x + 1 <= w) dp[x][y][chk][turn] = (dp[x][y][chk][turn] + func(x + 1, y, 0, turn)) % mod;
		}
	}
	else {
		if (turn) {
			if (y + 1 <= h) dp[x][y][chk][turn] = (dp[x][y][chk][turn] + func(x, y + 1, 0, turn)) % mod;
			if (x + 1 <= w) dp[x][y][chk][turn] = (dp[x][y][chk][turn] + func(x + 1, y, 1, 0)) % mod;
		}
		else {
			if (x + 1 <= w) dp[x][y][chk][turn] = (dp[x][y][chk][turn] + func(x + 1, y, 0, turn)) % mod;
			if (y + 1 <= h) dp[x][y][chk][turn] = (dp[x][y][chk][turn] + func(x, y + 1, 1, 1)) % mod;
		}
	}

	return dp[x][y][chk][turn] % mod;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> w >> h;
	memset(dp, -1, sizeof(dp));

	cout << (func(2, 1, 0, 0) + func(1, 2, 0, 1)) % mod << '\n';

	return 0;
}
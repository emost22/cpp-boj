#include <iostream>
#include <algorithm>
#include <cstring>
#define INF 1000000000
using namespace std;

int list[100001], dp[100001][5][5], po[5][5], N;

void init() {
	for (int i = 1; i <= 4; i++) {
		po[0][i] = 2;
		for (int j = i; j <= 4; j++) {
			if (i == j) po[i][j] = 1;
			else if (i % 2 != j % 2) {
				po[i][j] = 3;
				po[j][i] = 3;
			}
			else {
				po[i][j] = 4;
				po[j][i] = 4;
			}
		}
	}
}

int func(int idx, int l, int r) {
	if (idx == N) return 0;
	if (dp[idx][l][r] != -1) return dp[idx][l][r];
	dp[idx][l][r] = INF;

	if (list[idx] == l) dp[idx][l][r] = min(dp[idx][l][r], func(idx + 1, l, r) + po[l][list[idx]]);
	else if(list[idx] == r) dp[idx][l][r] = min(dp[idx][l][r], func(idx + 1, l, r) + po[r][list[idx]]);
	else {
		dp[idx][l][r] = min(dp[idx][l][r], min(func(idx + 1, list[idx], r) + po[l][list[idx]], func(idx + 1, l, list[idx]) + po[r][list[idx]]));
	}

	return dp[idx][l][r];
}

void input() {
	for (int i = 0; ; i++) {
		cin >> list[i];
		if (!list[i]) {
			N = i;
			break;
		}
	}
	memset(dp, -1, sizeof(dp));
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	input();
	cout << func(0, 0, 0) << '\n';

	return 0;
}
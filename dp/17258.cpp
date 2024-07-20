#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 310
using namespace std;

int dp[MAX][MAX][MAX];
int sum[MAX];
int N, M, K, T;

int solve(int idx, int k, int pre) {
	if (idx == N + 1) return 0;

	int& ret = dp[idx][k][pre];
	if (ret != -1) return ret;

	if (sum[idx] >= T) {
		return ret = solve(idx + 1, k, 0) + 1;
	}
	if (sum[idx] + pre >= T) {
		return ret = solve(idx + 1, k, pre) + 1;
	}

	ret = solve(idx + 1, k, pre);
	int tmp = T - (sum[idx] + pre);
	if (tmp <= k) {
		ret = max(ret, solve(idx + 1, k - tmp, pre + tmp) + 1);
	}
	return ret;
}

void init() {
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i < MAX; i++) {
		sum[i] += sum[i - 1];
	}
}

void func() {
	init();
	cout << solve(1, K, 0) << '\n';
}

void input() {
	int l, r;
	cin >> N >> M >> K >> T;
	while (M--) {
		cin >> l >> r;
		sum[l]++;
		sum[r]--;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
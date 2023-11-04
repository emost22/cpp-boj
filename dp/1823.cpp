#include <iostream>
#include <cstring>
#define MAX 2001
using namespace std;

int dp[MAX][MAX];
int list[MAX];
int N;

int solve(int l, int r, int cnt) {
	if (l > r) {
		return 0;
	}

	int& ret = dp[l][r];
	if (ret != -1) return ret;
	return ret = max(solve(l + 1, r, cnt + 1) + list[l] * cnt, solve(l, r - 1, cnt + 1) + list[r] * cnt);
}

void func() {
	memset(dp, -1, sizeof(dp));
	cout << solve(0, N - 1, 1) << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
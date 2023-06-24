#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 100001
using namespace std;

int list[MAX], dp[MAX][2];
int N;

int solve(int idx, bool flag) {
	if (idx >= N) return 0;
	
	int& ret = dp[idx][flag];
	if (ret != -1) return ret;
	ret = solve(idx + 1, false);

	if (!flag) {
		ret = max(ret, solve(idx + 1, true) + list[idx]);
	}
	else {
		ret = max(ret, solve(idx + 2, false) + (list[idx] >> 1));
	}

	return ret;
}

void func() {
	memset(dp, -1, sizeof(dp));

	cout << solve(0, false) << '\n';
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
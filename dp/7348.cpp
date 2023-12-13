#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 210
using namespace std;

int dp[MAX];
int N;

void func() {
	int ret = dp[0];
	for (int i = 1; i < MAX; i++) {
		dp[i] += dp[i - 1];
		ret = max(ret, dp[i]);
	}
	
	cout << ret * 10 << '\n';
}

void input() {
	int l, r;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> l >> r;
		if (l > r) swap(l, r);
		dp[(l - 1) >> 1]++;
		dp[(r + 1) >> 1]--;
	}
}

void init() {
	memset(dp, 0, sizeof(dp));
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
		init();
	}

	return 0;
}
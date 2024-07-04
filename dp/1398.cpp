#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 101
using namespace std;
typedef long long ll;

int dp[MAX];
int list[3] = { 1,10,25 };
ll N;

int solve(int n) {
	if (!n) return 0;

	int& ret = dp[n];
	if (ret != -1) return ret;

	ret = 1e9;
	for (int i = 0; i < 3; i++) {
		if (n < list[i]) continue;

		ret = min(ret, solve(n - list[i]) + 1);
	}
	return ret;
}

void func() {
	memset(dp, -1, sizeof(dp));
	
	int ret = 0;
	while (N) {
		ret += solve(N % 100LL);
		N /= 100LL;
	}
	cout << ret << '\n';
}

void input() {
	cin >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
	}

	return 0;
}
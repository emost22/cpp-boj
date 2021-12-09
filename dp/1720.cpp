#include <iostream>
#include <cstring>
#define MAX 31
using namespace std;

int dp[MAX];
int N;

int func(int idx) {
	if (idx == 0) return 1;
	else if (idx < 0) return 0;

	int &ret = dp[idx];
	if (ret != -1) return ret;
	ret = 0;

	ret += func(idx - 1);
	ret += (func(idx - 2) << 1);

	return ret;
}

void solve() {
	memset(dp, -1, sizeof(dp));

	if (N & 1) {
		cout << ((func(N) + func(N / 2)) >> 1) << '\n';
	}
	else {
		cout << ((func(N) + func(N / 2) + (func(N / 2 - 1) << 1)) >> 1) << '\n';
	}
}

void input() {
	cin >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	solve();

	return 0;
}
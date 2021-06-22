#include <iostream>
#include <cstring>
#define MOD 1000000007
using namespace std;

int dp[306][1 << 18];
int N, M;

int func(int x, int chk) {
	if (x == N * M) return 1;

	int &ret = dp[x][chk];
	if (ret != -1) return ret;
	ret = 0;

	ret = func(x + 1, chk >> 1);

	if (!(x % M) || !(chk & (1 << 0)) || !(chk & (1 << 1)) || !(chk & (1 << M))) {
		ret = (ret + func(x + 1, (chk >> 1) | (1 << M))) % MOD;
	}

	return ret;
}

void input() {
	cin >> N >> M;
	if (N < M) swap(N, M);
	memset(dp, -1, sizeof(dp));
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	cout << func(0, 0) << '\n';

	return 0;
}
#include <iostream>
#include <cstring>
#define MAX 14
#define MOD 9901
using namespace std;

int dp[MAX * MAX][1 << MAX];
int N, M;

int func(int x, int bit) {
	if (x == N * M) return 1;

	int &ret = dp[x][bit];
	if (ret != -1) return ret;
	ret = 0;

	if (bit & 1) ret = func(x + 1, (bit >> 1));
	else {
		if (x / M != N - 1) ret = func(x + 1, (bit >> 1) | (1 << (M - 1)));

		if (x % M != M - 1 && !(bit & 2)) ret = (ret + func(x + 2, bit >> 2)) % MOD;
	}

	return ret;
}

void input() {
	cin >> N >> M;
	memset(dp, -1, sizeof(dp));
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	cout << func(0, 0) << '\n';

	return 0;
}
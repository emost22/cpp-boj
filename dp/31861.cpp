#include <iostream>
#include <cstring>
#include <algorithm>
#define MOD 1000000007
#define MAX 1001
#define ALP 26
using namespace std;

int dp[MAX][ALP];
int N, M;

int makePassword(int idx, char x) {
	if (idx == M - 1) return 1;

	int& ret = dp[idx][x - 'A'];
	if (ret != -1) return ret;
	ret = 0;

	for (char i = 'A'; i <= 'Z'; i++) {
		if (abs(x - i) < N) continue;

		ret = (ret + makePassword(idx + 1, i)) % MOD;
	}

	return ret;
}

void func() {
	memset(dp, -1, sizeof(dp));

	int ret = 0;
	for (int i = 0; i < 26; i++) {
		ret = (ret + makePassword(0, (char)(i + 'A'))) % MOD;
	}

	cout << ret << '\n';
}

void input() {
	cin >> N >> M;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
#include <iostream>
#include <cstring>
#include <string>
#define MAX 200001
#define MOD 1000000007
using namespace std;

string str;
string findStr = "WHEE";
int dp[MAX][4], eCnt[MAX];
int N;

int solve(int sIdx, int fIdx) {
	if (fIdx == 4) return eCnt[sIdx];
	if (sIdx == N) return 0;

	int& ret = dp[sIdx][fIdx];
	if (ret != -1) return ret;
	ret = solve(sIdx + 1, fIdx);

	if (str[sIdx] == findStr[fIdx]) {
		ret = (ret + solve(sIdx + 1, fIdx + 1)) % MOD;
	}

	return ret;
}

void func() {
	fill(eCnt, eCnt + N + 1, 1);
	if (str[N - 1] == 'E') eCnt[N - 1] = 2;
	for (int i = N - 2; i >= 0; i--) {
		eCnt[i] = eCnt[i + 1];
		if (str[i] == 'E') {
			eCnt[i] = (eCnt[i] * 2) % MOD;
		}
	}

	memset(dp, -1, sizeof(dp));
	cout << solve(0, 0) << '\n';
}

void input() {
	cin >> N >> str;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
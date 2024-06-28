#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#define MAX 3010
using namespace std;

string s1, s2;
int dp[MAX][MAX];
int a, b, c;
int len1, len2;

int solve(int idx1, int idx2) {
	if (idx1 == len1) return (len2 - idx2) * b;
	if (idx2 == len2) return (len1 - idx1) * b;

	int& ret = dp[idx1][idx2];
	if (ret != -1) return ret;
	ret = b + max(solve(idx1 + 1, idx2), solve(idx1, idx2 + 1));
	if (s1[idx1] == s2[idx2]) {
		ret = max(ret, solve(idx1 + 1, idx2 + 1) + a);
	}
	else {
		ret = max(ret, solve(idx1 + 1, idx2 + 1) + c);
	}

	return ret;
}

void func() {
	memset(dp, -1, sizeof(dp));
	cout << solve(0, 0) << '\n';
}

void input() {
	cin >> a >> b >> c >> s1 >> s2;
	len1 = s1.size();
	len2 = s2.size();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
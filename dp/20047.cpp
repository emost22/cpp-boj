#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#define MAX 10000
using namespace std;

string str, ans, sub;
int dp[MAX][3];
int N;

int moveCoin(int strIdx, int ansIdx, int idx) {
	int &ret = dp[ansIdx][idx];
	if (ret != -1) return ret;

	if (ansIdx == N) {
		if (idx == 2) return ret = 1;
		else return ret = 0;
	}

	ret = 0;

	if (idx < 2) {
		if (sub[idx] == ans[ansIdx]) {
			ret |= moveCoin(strIdx, ansIdx + 1, idx + 1);
		}
	}

	if (str[strIdx] == ans[ansIdx] && strIdx < N - 2) {
		ret |= moveCoin(strIdx + 1, ansIdx + 1, idx);
	}

	return ret;
}

void func() {
	if (moveCoin(0, 0, 0)) cout << "YES\n";
	else cout << "NO\n";
}

void input() {
	int x, y;
	cin >> N >> str >> ans >> x >> y;
	sub += str[x];
	sub += str[y];
	str.erase(str.begin() + y);
	str.erase(str.begin() + x);

	memset(dp, -1, sizeof(dp));
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
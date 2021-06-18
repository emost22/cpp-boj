#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string str;
int dp[41];
int N;

int func(int idx) {
	if (idx == N) return 1;
	if (str[idx] == '0') return 0;

	int &ret = dp[idx];
	if (ret != -1) return ret;
	ret = 0;

	int now = 0;
	for (int i = idx; i < N; i++) {
		now = now * 10 + str[i] - '0';
		if (now > 34) break;

		ret += func(i + 1);
	}

	return ret;
}

void input() {
	cin >> str;
	N = str.size();
	memset(dp, -1, sizeof(dp));
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	cout << func(0) << '\n';

	return 0;
}
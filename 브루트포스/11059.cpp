#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;

string str;
int dp[MAX];
int len;

void func() {
	for (int i = 1; i <= len; i++) {
		dp[i] += (dp[i - 1] + str[i] - '0');
	}

	int ret = 0;
	for (int i = 2; i <= len; i += 2) {
		for (int j = 1; j <= len - i + 1; j++) {
			int m = (j + j + i - 1) >> 1;
			if (dp[m] - dp[j - 1] != dp[j + i - 1] - dp[m]) continue;
			ret = i;
			break;
		}
	}
	cout << ret << '\n';
}

void input() {
	cin >> str;
	len = str.size();
	str = " " + str;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
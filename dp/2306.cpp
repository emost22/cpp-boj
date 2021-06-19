#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str;
int dp[501][501];
int strLength, ans;

void func() {
	for (int k = 1; k < strLength; k++) {
		for (int i = 1; i + k <= strLength; i++) {
			if (str[i] == 'a' && str[i + k] == 't') dp[i][i + k] = dp[i + 1][i + k - 1] + 2; if (str[i] == 'a' && str[i + k] == 't') dp[i][i + k] = dp[i + 1][i + k - 1] + 2;
			else if (str[i] == 'g' && str[i + k] == 'c') dp[i][i + k] = dp[i + 1][i + k - 1] + 2; if (str[i] == 'a' && str[i + k] == 't') dp[i][i + k] = dp[i + 1][i + k - 1] + 2;

			for (int j = i; j < i + k; j++) {
				dp[i][i + k] = max(dp[i][i + k], dp[i][j] + dp[j + 1][i + k]);
			}
		}
	}

	cout << dp[1][strLength] << '\n';
}

void input() {
	cin >> str;
	strLength = str.size();
	str.insert(0, " ");
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
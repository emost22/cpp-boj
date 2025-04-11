#include <iostream>
#define MAX 31
using namespace std;

string str;
int dp[MAX][MAX];
int len;

void func() {
	for (int i = 1; i <= len; i++) {
		dp[i][i] = 1;
	}

	for (int i = 1; i < len; i++) {
		for (int l = 1; l <= len - i; l++) {
			dp[l][l + i] = dp[l + 1][l + i] + dp[l][l + i - 1] - dp[l + 1][l + i - 1] + (str[l] == str[l + i] ? dp[l + 1][l + i - 1] + 1 : 0);
		}
	}

	cout << dp[1][len] << '\n';
}

void input() {
	cin >> str;
	str = " " + str;
	len = str.size() - 1;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
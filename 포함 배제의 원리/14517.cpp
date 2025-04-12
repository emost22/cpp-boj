#include <iostream>
#include <string>
#define MAX 1001
#define MOD 10007
using namespace std;

string str;
int dp[MAX][MAX];
int len = 0;

void func() {
	for (int i = 1; i <= len; i++) {
		dp[i][i] = 1;
	}

	for (int i = 1; i < len; i++) {
		for (int l = 1; l <= len - i; l++) {
			dp[l][l + i] = (dp[l + 1][l + i] + dp[l][l + i - 1] - dp[l + 1][l + i - 1] + (str[l] == str[l + i] ? dp[l + 1][l + i - 1] + 1 : 0) + MOD) % MOD;
		}
	}
	cout << dp[1][len] << '\n';
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
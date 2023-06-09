#include <iostream>
#include <algorithm>
#include <string>
#define MAX 1001
using namespace std;

string str1, str2;
int dp[MAX][MAX];
int aLen, bLen;

void init() {
	for (int i = 1; i <= aLen; i++) {
		dp[i][0] = i;
	}

	for (int i = 1; i <= bLen; i++) {
		dp[0][i] = i;
	}
}

void func() {
	init();

	for (int i = 1; i <= aLen; i++) {
		for (int j = 1; j <= bLen; j++) {
			if (str1[i] == str2[j]) {
				dp[i][j] = dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
			}
		}
	}

	cout << dp[aLen][bLen] << '\n';
}

void input() {
	cin >> str1 >> str2;
	aLen = str1.size();
	bLen = str2.size();
	str1 = 'A' + str1;
	str2 = 'A' + str2;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
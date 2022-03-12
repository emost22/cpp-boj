#include <iostream>
#include <algorithm>
#include <string>
#define MAX 2001
using namespace std;

string str;
bool dp[MAX][MAX];
int ans[MAX];
int N;

void init() {
	for (int i = 1; i <= N; i++) {
		dp[i][i] = true;
		if (str[i - 1] == str[i]) dp[i - 1][i] = true;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= N - i; j++) {
			if (str[j] == str[i + j] && dp[j + 1][i + j - 1]) dp[j][i + j] = true;
		}
	}
}

void func() {
	init();

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			if (!dp[j][i]) continue;

			if (!ans[i] || ans[i] > ans[j - 1] + 1) {
				ans[i] = ans[j - 1] + 1;
			}
		}
	}

	cout << ans[N] << '\n';
}

void input() {
	cin >> str;
	N = str.size();
	str = " " + str;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
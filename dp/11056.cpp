#include <iostream>
#include <string>
#include <algorithm>
#define MAX 1001
using namespace std;

string str1, str2;
int dp[MAX][MAX];
int N, M;

void func() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (str1[i] == str2[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	cout << N + M - dp[N][M] << '\n';
}

void input() {
	cin >> str1 >> str2;
	N = str1.size();
	M = str2.size();
	str1 = " " + str1;
	str2 = " " + str2;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
#include <iostream>
#include <string>
#include <algorithm>
#define MAX 3001
using namespace std;

string str1, str2;
int dp[MAX][MAX];
int N, M;

void func() {
	for (int i = 3; i <= N; i += 3) {
		for (int j = 3; j <= M; j += 3) {
			if (str1.substr(i - 3, 3) == str2.substr(j - 3, 3)) {
				dp[i][j] = dp[i - 3][j - 3] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 3][j], dp[i][j - 3]);
			}
		}
	}

	cout << dp[N][M] << '\n';
}

void input() {
	cin >> str1 >> str2;
	N = str1.size();
	M = str2.size();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
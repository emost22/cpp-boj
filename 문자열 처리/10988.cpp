#include <iostream>
using namespace std;

char str[101];
int dp[101][101];

int find(int N) {
	for (int k = 2; k <= N - 1; k++) {
		for (int i = 1; i <= N - k; i++) {
			if (str[i] == str[i + k] && dp[i + 1][i + k - 1]) {
				dp[i][i + k] = 1;
			}
		}
	}

	return dp[1][N];
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int e;

	cin >> str + 1;
	for (int i = 1; str[i]; i++) {
		dp[i][i] = 1;
		if (str[i] == str[i - 1]) {
			dp[i - 1][i] = 1;
		}

		if (str[i + 1] == NULL) e = i;
	}

	cout << find(e) << '\n';

	return 0;
}
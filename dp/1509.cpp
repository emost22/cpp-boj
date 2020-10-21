#include <iostream>
#define INF 1000000000
using namespace std;

char str[2501];
int dp[2501][2501], min_dp[2501], e, ans;

int Min(int x, int y) {
	return x < y ? x : y;
}

void find() {
	for (int k = 2; k < e; k++) {
		for (int i = 1; i <= e - k; i++) {
			if (str[i] == str[i + k] && dp[i + 1][i + k - 1]) {
				dp[i][i + k] = 1;
			}
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> str + 1;
	for (int i = 1; str[i]; i++) {
		dp[i][i] = 1;
		if (str[i] == str[i - 1]) {
			dp[i - 1][i] = 1;
		}
		if (!str[i + 1]) e = i;
	}
	find();

	for (int i = 1; str[i]; i++) {
		min_dp[i] = INF;
		for (int j = 1; j <= i; j++) {
			if (dp[j][i]) {
				min_dp[i] = Min(min_dp[i], min_dp[j - 1] + 1);
			}
		}
	}

	cout << min_dp[e] << '\n';

	return 0;
}
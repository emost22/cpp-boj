#include <iostream>
using namespace std;

char str1[101], str2[101], str3[101];
int dp[101][101][101], x, y, z;

int Max(int x, int y) {
	return x > y ? x : y;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> str1 + 1 >> str2 + 1 >> str3 + 1;

	for (int i = 1; str1[i]; i++) {
		for (int j = 1; str2[j]; j++) {
			for (int k = 1; str3[k]; k++) {
				if (str1[i] == str2[j] && str2[j] == str3[k]) {
					dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
				}
				else {
					int max1 = Max(dp[i - 1][j][k], Max(dp[i][j - 1][k], dp[i][j][k - 1]));
					int max2 = Max(dp[i - 1][j - 1][k], Max(dp[i - 1][j][k - 1], dp[i][j - 1][k - 1]));
					dp[i][j][k] = Max(max1, max2);
				}

				if (!str1[i + 1] && !str2[j + 1] && !str3[k + 1]) {
					x = i;
					y = j;
					z = k;
				}
			}
		}
	}

	cout << dp[x][y][z] << '\n';

	return 0;
}
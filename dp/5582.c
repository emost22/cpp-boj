#include <stdio.h>

char str1[4001], str2[4001];
int dp[4001][4001], length;

int Max(int x, int y) {
	return x > y ? x : y;
}

int find() {
	for (int i = 1; str1[i]; i++) {
		for (int j = 1; str2[j]; j++) {
			if (str1[i] == str2[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				length = Max(length, dp[i][j]);
			}
		}
	}

	return length;
}

int main() {
	scanf("%s\n%s", str1 + 1, str2 + 1);

	printf("%d\n", find());

	return 0;
}
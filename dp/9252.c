#include <stdio.h>

int dp[1001][1001], index;
char list1[1001], list2[1001], LCS[1001];

int Max(int x, int y) {
	return x > y ? x : y;
}

int main() {
	int s, e;
	scanf("%s %s", list1 + 1, list2 + 1);

	for (int i = 1; list1[i]; i++) {
		for (int j = 1; list2[j]; j++) {
			if (list1[i] == list2[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else dp[i][j] = Max(dp[i - 1][j], dp[i][j - 1]);
			if (list2[j + 1] == NULL) e = j;
		}
		if (list1[i + 1] == NULL) s = i;
	}

	printf("%d\n", dp[s][e]);

	while (1) {
		if (s == 0 || e == 0) break;
		if (dp[s][e] == dp[s - 1][e]) s--;
		else if (dp[s][e] == dp[s][e - 1]) e--;
		else {
			LCS[index++] = list2[e];
			s--;
			e--;
		}
	}

	for (int i = index - 1; i >= 0; i--) {
		printf("%c", LCS[i]);
	}
	printf("\n");

	return 0;
}
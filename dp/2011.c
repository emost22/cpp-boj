#include <stdio.h>
#define mod 1000000

int dp[5001];
char pass[5001];

int main() {
	int x;

	scanf("%s", pass + 1);

	if (!strcmp(pass + 1, "0")) {
		printf("0\n");
		return 0;
	}

	if (pass[1] == '0') {
		printf("0\n");
		return 0;
	}

	if (pass[2] == NULL) {
		printf("1\n");
		return 0;
	}

	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; pass[i]; i++) {
		if (pass[i] > 48) {
			dp[i] = dp[i - 1];
		}
		x = (pass[i - 1] - 48) * 10 + (pass[i] - 48);

		if (10 <= x && x <= 26) {
			dp[i] = (dp[i] + dp[i - 2]) % mod;
		}

		if (pass[i] == 48 && (x < 10 || x>26)) {
			printf("0\n");
			break;
		}

		if (pass[i + 1] == NULL) {
			printf("%d\n", dp[i]);
		}
	}

	return 0;
}
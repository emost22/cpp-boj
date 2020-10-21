#include <stdio.h>

int dp[101][1001];
int max_vol, check;

int Max(int x, int y) {
	return x > y ? x : y;
}

int main() {
	int N, S, M, vol;

	scanf("%d %d %d", &N, &S, &M);

	dp[0][S] = 1;
	for (int i = 1; i <= N; i++) {
		scanf("%d", &vol);

		for (int j = 0; j <= M; j++) {
			if (dp[i - 1][j]) {
				if (j + vol <= M) {
					dp[i][j + vol] = 1;
					check++;
				}
				if (j - vol >= 0) {
					dp[i][j - vol] = 1;
					check++;
				}
			}
		}
		if (!check) {
			max_vol = -1;
			break;
		}
		check = 0;
	}

	if(max_vol != -1) {
		for (int i = 0; i <= M; i++) {
			if (dp[N][i]) {
				max_vol = Max(max_vol, i);
			}
		}
	}

	printf("%d\n", max_vol);

	return 0;
}
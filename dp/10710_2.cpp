#include <iostream>
#define INF 1000000000
using namespace std;

int dp[1001][1001][2];
int d[1001], c[1001], N, M;

int Min(int x, int y) {
	return x < y ? x : y;
}

int func() {
	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= M; j++) {
			if (i > 1) {
				int min_value = INF;
				for (int k = 1; k < j; k++) {
					if (i - 1 > k) continue;
					min_value = Min(min_value, dp[i - 1][k][1]);
				}
				dp[i][j][0] = min_value;
			}
			dp[i][j][1] = dp[i][j][0] + d[i] * c[j];
		}
	}

	int min_value = INF;
	for (int i = N; i <= M; i++) {
		min_value = Min(min_value, dp[N][i][1]);
	}

	return min_value;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> d[i];
	}
	for (int i = 1; i <= M; i++) {
		cin >> c[i];
	}

	cout << func() << '\n';

	return 0;
}
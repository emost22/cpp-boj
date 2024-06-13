#include <iostream>
#include <algorithm>
#define MAX 1501
using namespace std;

int sumA[MAX][MAX], sumB[MAX][MAX], dp[MAX][MAX];
int N, M;

void func() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (j == 1) {
				dp[i][j] = sumA[N][j] - sumA[i][j];
				continue;
			}

			int tmp = sumA[N][j] - sumA[i][j] + sumB[i - 1][j];
			dp[i][j] = max(max(dp[i - 1][j - 1], dp[i][j - 1]) + tmp, dp[i - 1][j] - sumA[i][j] + sumA[i - 1][j]);
		}
	}

	cout << dp[N][M] << '\n';
}

void input() {
	char ch;
	int x;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> ch >> x;
			if (ch == 'A') {
				sumA[i][j] = x;
			}
			else {
				sumB[i][j] = x;
			}
			sumA[i][j] += sumA[i - 1][j];
			sumB[i][j] += sumB[i - 1][j];
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
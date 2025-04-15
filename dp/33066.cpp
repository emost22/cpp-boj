#include <iostream>
#define MAX 2001
using namespace std;

int list[MAX][MAX], ret[MAX][MAX];
int dp[MAX][MAX];
int N, M, K, S;

int getSum(int sx, int sy, int ex, int ey) {
	return dp[ex][ey] - dp[sx - 1][ey] - dp[ex][sy - 1] + dp[sx - 1][sy - 1];
}

void func() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			dp[i][j] = list[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
		}
	}

	int x = 1;
	int y = 1;
	for (int i = 1; i <= N - K + 1; i += S) {
		for (int j = 1; j <= M - K + 1; j += S) {
			int r = getSum((i + i + K - 1) >> 1, j, (i + i + K - 1) >> 1, j + K - 1);
			int c = getSum(i, (j + j + K - 1) >> 1, i + K - 1, (j + j + K - 1) >> 1);
			ret[x][y++] = r + c - list[(i + i + K - 1) >> 1][(j + j + K - 1) >> 1];
		}
		y = 1;
		x++;
	}

	for (int i = 1; i <= (N - K) / S + 1; i++) {
		for (int j = 1; j <= (M - K) / S + 1; j++) {
			cout << ret[i][j] << ' ';
		}
		cout << '\n';
	}
}

void input() {
	cin >> N >> M >> K >> S;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> list[i][j];
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
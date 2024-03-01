#include <iostream>
#define MAX 301
using namespace std;

int dp[MAX][MAX];
bool chk[MAX][MAX];
int N, M;

void func() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			if (!i && !j) continue;

			if (!i) {
				if (chk[i][j]) {
					dp[i][j] = dp[i][j - 1] + max(0, M - i - j);
				}
				else {
					dp[i][j] = dp[i][j - 1];
				}
			}
			else if (!j) {
				if (chk[i][j]) {
					dp[i][j] = dp[i - 1][j] + max(0, M - i - j);
				}
				else {
					dp[i][j] = dp[i - 1][j];
				}
			}
			else {
				if (chk[i][j]) {
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + max(0, M - i - j);
				}
				else {
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}
	}

	cout << dp[MAX - 1][MAX - 1] << '\n';
}

void input() {
	int x, y;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		chk[x][y] = true;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
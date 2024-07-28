#include <iostream>
#define MAX 2001
using namespace std;

int dp[MAX][MAX];
int N, M, Q;

void func() {
	int x, y;
	while (Q--) {
		cin >> x >> y;
		cout << dp[x][y] << '\n';
	}
}

void input() {
	cin >> N >> M >> Q;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> dp[i][j];
			dp[i][j] += (dp[i - 1][j] + dp[i - 1][j - 1]);
			if (i > 1) {
				dp[i][j] -= dp[i - 2][j - 1];
			}
		}
	}
}

int main() {
	cin.tie(nullptr); cout.tie(nullptr);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
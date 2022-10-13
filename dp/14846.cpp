#include <iostream>
#define MAX 301
using namespace std;

int list[MAX][MAX], dp[MAX][MAX][11];
int N, M;

void func() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= 10; k++) {
				dp[i][j][k] += (dp[i][j - 1][k] + dp[i - 1][j][k] - dp[i - 1][j - 1][k]);
			}
		}
	}

	int sx, sy, ex, ey;
	cin >> M;
	while (M--) {
		cin >> sx >> sy >> ex >> ey;

		int ans = 0;
		for (int i = 1; i <= 10; i++) {
			int cnt = dp[ex][ey][i] - dp[sx - 1][ey][i] - dp[ex][sy - 1][i] + dp[sx - 1][sy - 1][i];
			ans += (cnt ? 1 : 0);
		}

		cout << ans << '\n';
	}
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> list[i][j];
			dp[i][j][list[i][j]]++;
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
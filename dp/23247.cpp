#include <iostream>
#include <algorithm>
#define MAX 301
using namespace std;

int dp[MAX][MAX];
int N, M;

void func() {
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			for (int x = i; x <= N; x++) {
				for (int y = j; y <= M; y++) {
					int sum = dp[x][y] - dp[x][j - 1] - dp[i - 1][y] + dp[i - 1][j - 1];
					if (sum == 10) {
						ans++;
						break;
					}
					else if (sum > 10) break;
				}
			}
		}
	}

	cout << ans << '\n';
}

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> dp[i][j];
			dp[i][j] += (dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1]);
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
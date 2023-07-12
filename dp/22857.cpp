#include <iostream>
#define MAX_N 50001
#define MAX_K 101
using namespace std;

int dp[MAX_N][MAX_K], list[MAX_N];
int N, K;

void func() {
	int ret = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= K; j++) {
			if (list[i] % 2) {
				if (j > 0) {
					dp[i][j] = dp[i - 1][j - 1];
				}
			}
			else {
				dp[i][j] = dp[i - 1][j] + 1;
			}

			ret = max(ret, dp[i][j]);
		}
	}

	cout << ret << '\n';
}

void input() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
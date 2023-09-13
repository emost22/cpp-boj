#include <iostream>
#include <algorithm>
#define MAX 101
using namespace std;

int dp[MAX][MAX];
int N;

void func() {
	for (int i = 1; i < MAX; i++) {
		for (int j = 1; j < MAX; j++) {
			if (!dp[i][j]) continue;
			dp[i][j] += dp[i - 1][j];
		}
	}

	int ret = 0;
	for (int i = 1; i < MAX; i++) {
		for (int j = 1; j < MAX - 1; j++) {
			int h = dp[i][j];
			for (int k = j + 1; k < MAX; k++) {
				h = min(h, dp[i][k]);
				ret = max(ret, (k - j + 1) * h);
			}
		}
	}

	cout << ret << '\n';
}

void input() {
	int x, y;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		for (int j = x; j < x + 10; j++) {
			for (int k = y; k < y + 10; k++) {
				dp[j][k] = 1;
			}
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
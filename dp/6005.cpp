#include <iostream>
#include <algorithm>
#define MAX 26
using namespace std;

int dp[MAX][MAX];
int N;

void func() {
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + dp[i][j];
		}
	}

	int ret = 0;
	for (int i = 1; i <= N; i++) {
		ret = max(ret, dp[N][i]);
	}

	cout << ret << '\n';
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> dp[i][j];
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
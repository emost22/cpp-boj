#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;

int list[MAX], dp[MAX][2];
int N;

void func() {
	int ret = 0;
	for (int i = 1; i <= N; i++) {
		if (list[i] == 1) {
			dp[i][0] = 1;
			dp[i][1] = -1;
		}
		else {
			dp[i][1] = 1;
			dp[i][0] = -1;
		}
		dp[i][0] = max(dp[i][0] + dp[i - 1][0], 0);
		dp[i][1] = max(dp[i][1] + dp[i - 1][1], 0);

		ret = max(ret, max(dp[i][0], dp[i][1]));
	}

	cout << ret << '\n';
}

void input() {
	cin >> N;
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
#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 11
using namespace std;

int dp[MAX];
int N, Y;

void func() {
	dp[0] = N;
	for (int i = 1; i <= Y; i++) {
		dp[i] = dp[i - 1] * 1.05;
		if (i >= 3) {
			dp[i] = max(dp[i], (int)(dp[i - 3] * 1.2));
		}
		if (i >= 5) {
			dp[i] = max(dp[i], (int)(dp[i - 5] * 1.35));
		}
	}

	cout << dp[Y] << '\n';
}

void input() {
	cin >> N >> Y;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
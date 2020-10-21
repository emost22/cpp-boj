#include <iostream>
#include <algorithm>
using namespace std;

int dp[2001], clip = 1;

int func(int N) {
	dp[1] = 1;
	for (int i = 1; i <= 2000; i ++) {
		dp[i + 1] = dp[i] + 1;
	}

	while (clip <= 1001) {
		int r = dp[clip] + 2;
		dp[clip * 2] = min(dp[clip * 2], dp[clip] + 2);
		for (int i = clip * 3; i + clip <= 2000; i += clip) {
			dp[i] = min(dp[i], r + 1);
			r++;
		}

		for (int i = clip * 2 - 1; i >= clip + 1; i--) {
			dp[i] = min(dp[i], dp[i + 1] + 1);
		}
		clip++;
	}

	return dp[N];
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	cout << func(N) << '\n';

	return 0;
}
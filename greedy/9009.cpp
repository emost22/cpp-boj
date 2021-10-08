#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

stack<int> ans;
int dp[46];
int N;

void init() {
	dp[1] = 1;
	for (int i = 2; i < 46; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
}

void func() {
	for (int i = 0; i < 46; i++) {
		if (dp[i] == N) {
			cout << N << '\n';
			return;
		}

		if (dp[i] > N) {
			for (int j = i - 1; j > 0 && N; j--) {
				if (dp[j] <= N) {
					N -= dp[j];
					ans.push(dp[j]);
				}
			}

			if (!N) break;
		}
	}

	while (!ans.empty()) {
		cout << ans.top() << ' ';
		ans.pop();
	}
	cout << '\n';
}

void input() {
	cin >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;

	init();
	while (tc--) {
		input();
		func();
	}

	return 0;
}
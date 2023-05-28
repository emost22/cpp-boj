#include <iostream>
#include <algorithm>
#define MAX 1000001
using namespace std;

int dp[MAX];
int N, a, b;

void func() {
	for (int i = 1; i <= N; i++) {
		dp[i] = i;

		if ((i - 1) - a >= 0) {
			dp[i] = min(dp[i], dp[i - 1 - a] + 1);
		}

		if ((i - 1) - b >= 0) {
			dp[i] = min(dp[i], dp[i - 1 - b] + 1);
		}
	}

	cout << dp[N] << '\n';
}

void input() {
	cin >> N >> a >> b;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
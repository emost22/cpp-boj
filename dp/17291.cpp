#include <iostream>
#define MAX 25
using namespace std;

int dp[MAX];
int N;

void func() {
	dp[1] = 1;
	dp[4] -= 1;
	for (int i = 2; i <= N; i++) {
		dp[i] += dp[i - 1] << 1;
		if (i & 1) {
			dp[i + 3] -= dp[i - 1];
		}
		else {
			dp[i + 4] -= dp[i - 1];
		}
	}
	
	cout << dp[N] << '\n';
}

void input() {
	cin >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
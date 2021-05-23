#include <iostream>
using namespace std;

int dp[10000001];
int N;

void input() {
	cin >> N;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= N; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10;
	}

	cout << dp[N] << '\n';
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}
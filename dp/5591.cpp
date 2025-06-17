#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;

int dp[MAX];
int N, K;

void func() {
	for (int i = 1; i <= N; i++) {
		dp[i] += dp[i - 1];
	}

	int ret = -1e9;
	for (int i = 1; i <= N - K + 1; i++) {
		ret = max(ret, dp[i + K - 1] - dp[i - 1]);
	}
	cout << ret << '\n';
}

void input() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> dp[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
#include <iostream>
#include <algorithm>
#define MAX 1000001
using namespace std;

int dp[MAX];
int N;

void func() {
	int ret = 1e9;
	for (int i = 1; i < N; i++) {
		ret = min(ret, abs(dp[N] - dp[i] - dp[i]));
	}

	cout << ret << '\n';
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> dp[i];
		dp[i] += dp[i - 1];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
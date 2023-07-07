#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;

int list[MAX], dp[MAX];
int N;

void func() {
	int ret = 0;
	for (int i = 2; i < N; i++) {
		ret = max(ret, dp[N] - dp[1] - list[i] + dp[N] - dp[i]);
		ret = max(ret, dp[N - 1] - list[i] + dp[i - 1]);
		ret = max(ret, dp[i] - dp[1] + dp[N - 1] - dp[i - 1]);
	}

	cout << ret << '\n';
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> list[i];
		dp[i] = dp[i - 1] + list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
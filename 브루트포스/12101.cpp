#include <iostream>
#include <string>
using namespace std;

int dp[11], N, K;

void init() {
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i <= 10; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}
}

void func(int idx, int n, int k, string str) {
	if (n == 1) {
		str += '1';
		cout << str << '\n';
		return;
	}
	else if (n == 2 && k == 2) {
		str += '2';
		cout << str << '\n';
		return;
	}
	else if (n == 3 && k == 4) {
		str += '3';
		cout << str << '\n';
		return;
	}

	if (k > dp[idx]) {
		func(idx - 1, n, k - dp[idx], str);
	}
	else {
		str += (n - idx + '0');
		str += '+';
		func(idx - 1, idx, k, str);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	cin >> N >> K;
	if (dp[N] < K) {
		cout << "-1\n";
		return 0;
	}
	func(N - 1, N, K, "");

	return 0;
}
#include <iostream>
using namespace std;
typedef long long ll;

ll dp[91], N;

void init() {
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= 90; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
}

void solve() {
	int length = 0;
	for (int i = 1; i <= 90; i++) {
		if (dp[i] > N) {
			length = i - 1;
			break;
		}
	}

	while (length) {
		if (dp[length] <= N) {
			cout << 1;
			N -= dp[length];
		}
		else {
			cout << 0;
		}
		length--;
	}
	cout << '\n';
}

void input() {
	cin >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	input();
	solve();

	return 0;
}
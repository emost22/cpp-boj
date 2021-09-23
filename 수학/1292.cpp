#include <iostream>
using namespace std;

int dp[1001];
int l, r;

void init() {
	int now = 1;
	int cnt = 0;
	for (int i = 1; i <= 1000; i++) {
		dp[i] = dp[i - 1] + now;
		cnt++;
		if (now == cnt) {
			cnt = 0;
			now++;
		}
	}
}

void input() {
	cin >> l >> r;
	cout << dp[r] - dp[l - 1] << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	input();

	return 0;
}
#include <iostream>
using namespace std;

int dp[11], N;

void init() {
	for (int i = 2; i <= 10; i++) {
		int l = i / 2;
		int r = i - l;
		dp[i] = l * r + dp[l] + dp[r];
	}
}

void input() {
	cin >> N;
	cout << dp[N] << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	input();

	return 0;
}
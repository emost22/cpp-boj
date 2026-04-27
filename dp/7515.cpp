#include <iostream>
#define MAX 41
using namespace std;

int dp[MAX];
int N;

void init() {
	dp[1] = 2;
	dp[2] = 3;
	for (int i = 3; i < MAX; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
}

void func(int tc) {
	if (tc > 1) cout << '\n';
	cout << "Scenario " << tc << ":\n" << dp[N] << '\n';
}

void input() {
	cin >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		input();
		func(t);
	}

	return 0;
}
#include <iostream>
#define MAX 100001
#define MOD 16769023
using namespace std;

int dp[MAX];
int N;

void init() {
	dp[1] = 2;
	dp[2] = 2;
	for (int i = 3; i < MAX; i += 2) {
		dp[i] = (dp[i - 1] * 2) % MOD;
		dp[i + 1] = (dp[i - 1] * 2) % MOD;
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
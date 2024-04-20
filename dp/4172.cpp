#include <iostream>
#include <cmath>
#define MAX 1000001
#define MOD 1000000
using namespace std;

int dp[MAX];
int N;

void init() {
	dp[0] = 1;
	for (int i = 1; i < MAX; i++) {
		dp[i] = (dp[(int)(i - sqrt(i))] + dp[(int)log(i)] + dp[(int)(i * sin(i) * sin(i))]) % MOD;
	}
}

void input() {
	cin >> N;
	if (N == -1) exit(0);
	cout << dp[N] << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	while (1) {
		input();
	}

	return 0;
}
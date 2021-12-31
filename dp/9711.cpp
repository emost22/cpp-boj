#include <iostream>
#define MAX 10001
using namespace std;

unsigned int dp[MAX];
int N, M;

void func() {
	dp[1] = 1 % M;
	dp[2] = 1 % M;
	for (int i = 3; i <= N; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % M;
	}
}

void input() {
	cin >> N >> M;
}

void init() {
	for (int i = 1; i <= N; i++) dp[i] = 0;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		input();
		func();
		cout << "Case #" << t << ": " << dp[N] << '\n';
	}

	return 0;
}
#include <iostream>
#define MAX 10001
#define MOD 1000000007
using namespace std;

int dp[MAX];
int N, M;

void func() {
	for (int i = 1; i < M; i++) {
		dp[i] = 1;
	}
	dp[M] = 2;

	for (int i = M + 1; i <= N; i++) {
		dp[i] = (dp[i - 1] + dp[i - M]) % MOD;
	}

	cout << dp[N] << '\n';
}

void input() {
	cin >> N >> M;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
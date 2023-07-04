#include <iostream>
#define MAX 16
#define MOD 1000000007
using namespace std;
typedef long long ll;

ll dp[MAX][2];
ll C, V, L;

void func(int tc) {
	dp[1][0] = V;
	for (int i = 2; i <= L; i++) {
		dp[i][0] = (dp[i - 1][0] * V % MOD + dp[i - 1][1] * V % MOD) % MOD;
		dp[i][1] = (dp[i - 1][0] * C) % MOD;
	}

	cout << "Case #" << tc << ": " << (dp[L][0] + dp[L][1]) % MOD << '\n';
}

void input() {
	cin >> C >> V >> L;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		input();
		func(t);
	}

	return 0;
}
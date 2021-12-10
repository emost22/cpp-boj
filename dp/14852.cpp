#include <iostream>
#define MAX 1000001
#define MOD 1000000007
using namespace std;
typedef long long ll;

ll dp[MAX][2];
int N;

void init() {
	dp[1][0] = 2;
	dp[2][0] = 7;
	dp[2][1] = 1;
	for (int i = 3; i < MAX; i++) {
		dp[i][1] = (dp[i - 1][1] + dp[i - 3][0]) % MOD;
		dp[i][0] = (2 * dp[i - 1][0] + 3 * dp[i - 2][0] + 2 * dp[i][1]) % MOD;
	}
}

void input() {
	cin >> N;
	cout << dp[N][0] << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	input();

	return 0;
}
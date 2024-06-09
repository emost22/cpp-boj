#include <iostream>
#include <cstring>
#define MAX 64
using namespace std;
typedef long long ll;

ll dp[MAX][MAX];
int N, K;

ll solve(int n, int k) {
	if (!k) return 0LL;
	if (!n) return 1LL;
	
	ll& ret = dp[n][k];
	if (ret != -1) return ret;
	return ret = solve(n - 1, k + 1) + solve(n - 1, k - 1);
}

void func() {
	memset(dp, -1, sizeof(dp));
	cout << solve(N, K) << '\n';
}

void input() {
	cin >> K >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
#include <iostream>
#include <algorithm>
#define MAX 10000001
using namespace std;
typedef long long ll;

ll dp[MAX];
ll N, p, q, x, y;

ll solve(ll n) {
	if (n < MAX) return dp[n];

	ll l = 1LL;
	if (n / p - x > 0) l = solve(n / p - x);

	ll r = 1LL;
	if (n / q - y > 0) r = solve(n / q - y);

	return l + r;
}

void init() {
	dp[0] = 1LL;
	for (int i = 1; i < MAX; i++) {
		dp[i] = dp[max(0LL, i / p - x)] + dp[max(0LL, i / q - y)];
	}
}

void func() {
	init();
	cout << solve(N) << '\n';
}

void input() {
	cin >> N >> p >> q >> x >> y;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
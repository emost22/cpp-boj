#include <iostream>
#define MAX 55
using namespace std;
typedef long long ll;

ll dp[MAX];
ll A, B;

ll solve(ll x) {
	ll ret = 0;
	for (ll i = MAX - 1; i >= 0; i--) {
		ll y = 1LL << i;
		if (x & y) {
			ret += (dp[i - 1] + x - y + 1);
			x -= y;
		}
	}

	return ret;
}

void func() {
	cout << solve(B) - solve(A - 1) << '\n';
}

void init() {
	dp[0] = 1;
	for (ll i = 1; i < MAX; i++) {
		dp[i] = dp[i - 1] * 2 + (1LL << (i - 1));
	}

	for (ll i = 1; i < MAX; i++) {
		dp[i] += dp[i - 1];
	}
}

void input() {
	cin >> A >> B;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	input();
	func();

	return 0;
}
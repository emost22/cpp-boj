#include <iostream>
#define MOD 1000000007
using namespace std;
typedef long long ll;

ll a, b;

ll mulNum(ll x, ll y) {
	return (x * y) % MOD;
}

ll solve(ll n) {
	if (n == 1LL) return a;

	if (n % 2LL) {
		ll pre = solve(n - 1LL);
		return mulNum(pre, a);
	}
	else {
		ll pre = solve(n / 2LL);
		return mulNum(pre, pre);
	}
}

void func() {
	cout << solve(b) << '\n';
}

void input() {
	cin >> a >> b;
	a %= MOD;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
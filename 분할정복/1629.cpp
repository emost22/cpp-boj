#include <iostream>
using namespace std;
typedef long long ll;

ll x, mod;
int y;

ll mulNum(ll a, ll b) {
	return (a * b) % mod;
}

ll solve(int n) {
	if (n == 1) return x;
	
	if (n % 2) {
		ll pre = solve(n - 1);
		return mulNum(pre, x);
	}
	else {
		ll pre = solve(n / 2);
		return mulNum(pre, pre);
	}
}

void func() {
	cout << solve(y) << '\n';
}

void input() {
	cin >> x >> y >> mod;
	x %= mod;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
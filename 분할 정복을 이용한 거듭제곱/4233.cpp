#include <iostream>
using namespace std;
typedef long long ll;

ll p, a;

bool isPrime(ll x) {
	if (!(x & 1)) return false;

	for (ll i = 3; i * i <= x; i += 2) {
		if (!(x % i)) return false;
	}
	return true;
}

ll power(ll x, ll y) {
	ll ret = 1LL;
	while (y) {
		if (y & 1) ret = (ret * x) % p;
		x = (x * x) % p;
		y >>= 1;
	}
	return ret;
}

void func() {
	if (isPrime(p)) {
		cout << "no\n";
		return;
	}

	if (power(a, p) == a) cout << "yes\n";
	else cout << "no\n";
}

void input() {
	cin >> p >> a;
	if (!p || !a) exit(0);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (1) {
		input();
		func();
	}

	return 0;
}
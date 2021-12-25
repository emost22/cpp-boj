#include <iostream>
using namespace std;
typedef long long ll;

ll x, y;

ll gcd(ll a, ll b) {
	ll q, r, s, t;
	ll r1 = a;
	ll r2 = b;
	ll s1 = 1;
	ll s2 = 0;
	ll t1 = 0;
	ll t2 = 1;
	while (r2) {
		q = (r1 / r2);
		r = r1 - (q * r2);
		s = s1 - (q * s2);
		t = t1 - (q * t2);

		r1 = r2;
		r2 = r;
		s1 = s2;
		s2 = s;
		t1 = t2;
		t2 = t;
	}

	if (r1 != 1) return -1;
	else return (t1 + a) % a;
}

void func() {
	cout << x - y << ' ' << gcd(x, y) << '\n';
}

void input() {
	cin >> x >> y;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
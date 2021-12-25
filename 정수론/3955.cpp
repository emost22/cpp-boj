#include <iostream>
using namespace std;
typedef long long ll;

ll x, y;

ll gcd() {
	ll q, r, s, t;
	ll r1 = x;
	ll r2 = y;
	ll s1 = 1;
	ll s2 = 0;
	ll t1 = 0;
	ll t2 = 1;
	while (r2) {
		q = r1 / r2;
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
	r = r1;
	s = s1;
	t = t1;

	if (r == 1) return (t + x) % x;
	else return -1;
}

void func() {
	ll ans = gcd();
	if (ans == -1) cout << "IMPOSSIBLE\n";
	else {
		while (ans * y <= x) ans += x;
		
		if (ans > 1e9) cout << "IMPOSSIBLE\n";
		else cout << ans << '\n';
	}
}

void input() {
	cin >> x >> y;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
	}

	return 0;
}
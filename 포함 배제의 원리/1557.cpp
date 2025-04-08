#include <iostream>
#define MAX 41000
using namespace std;
typedef long long ll;

ll mobius[MAX];
ll K;

ll getNumber(ll x) {
	ll ret = 0;
	for (ll i = 1; i * i <= x; i++) {
		ret += (mobius[i] * (x / (i * i)));
	}
	return ret;
}

ll bs(ll l, ll r) {
	ll ret = 0;
	while (l <= r) {
		ll m = (l + r) >> 1;
		if (getNumber(m) < K) {
			l = m + 1;
		}
		else {
			ret = m;
			r = m - 1;
		}
	}
	return ret;
}

void init() {
	bool* chk = new bool[MAX] {false, };
	fill(mobius, mobius + MAX, 1);
	mobius[0] = 0;
	for (ll i = 2; i < MAX; i++) {
		if (chk[i]) continue;
		for (ll j = 1; i * j < MAX; j++) {
			mobius[i * j] *= -1;
			if (j > 1) chk[i * j] = true;
			if (i * i * j < MAX) mobius[i * i * j] = 0;
		}
	}
}

void func() {
	init();
	cout << bs(0, 2e9) << '\n';
}

void input() {
	cin >> K;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
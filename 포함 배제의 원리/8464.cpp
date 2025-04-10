#include <iostream>
#define MAX 1000001
using namespace std;
typedef long long ll;

ll mobius[MAX];
ll N;

ll getNumber(ll x) {
	ll ret = 0;
	for (ll i = 1; i * i <= x; i++) {
		ret += (mobius[i] * (x / (i * i)));
	}
	return x - ret;
}

ll bs(ll l, ll r) {
	ll ret = 0;
	while (l <= r) {
		ll m = (l + r) >> 1;
		if (getNumber(m) < N) {
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
	fill(mobius, mobius + MAX, 1);
	bool* chk = new bool[MAX] {false, };
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
	cout << bs(0, 1e11) << '\n';
}

void input() {
	cin >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
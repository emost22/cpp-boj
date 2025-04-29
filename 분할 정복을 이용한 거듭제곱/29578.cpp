#include <iostream>
using namespace std;
typedef long long ll;

int N;

ll power(ll x, int y, ll mod) {
	ll ret = 1LL;
	while (y) {
		if (y & 1) ret = (ret * x) % mod;
		x = (x * x) % mod;
		y >>= 1;
	}
	return ret;
}

void func() {
	int cnt = 0;
	for (int i = 1; ; i++) {
		ll sum = 1LL;
		for (ll j = 2; j <= 6; j++) {
			sum = (sum + power(j, i, (ll)i)) % (ll)i;
		}

		cnt += (sum == 0);
		if (cnt == N) {
			cout << i << '\n';
			return;
		}
	}
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
#include <iostream>
#define MOD 1000000007
using namespace std;
typedef long long ll;

ll N, K;

ll power(ll x, ll y) {
	ll ret = 1LL;
	while (y) {
		if (y & 1) ret = (ret * x) % MOD;
		x = (x * x) % MOD;
		y >>= 1;
	}
	return ret;
}

ll fact(ll x) {
	ll ret = 1LL;
	while (x) {
		ret = (ret * x--) % MOD;
	}
	return ret;
}

void func() {
	ll x = fact(N);
	ll y = (fact(K) * fact(N - K)) % MOD;
	cout << (x * power(y, MOD - 2LL)) % MOD << '\n';
}

void input() {
	cin >> N >> K;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
#include <iostream>
#define MOD 1000000007
using namespace std;
typedef long long ll;

ll N;

ll power(ll x, ll y) {
	ll ret = 1LL;
	while (y) {
		if (y & 1) ret = (ret * x) % MOD;
		x = (x * x) % MOD;
		y >>= 1;
	}
	return ret;
}

void func() {
	if (N < 2LL) cout << "1\n";
	else cout << power(2LL, N - 2LL) << '\n';
}

void input() {
	cin >> N;
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
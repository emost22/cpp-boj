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
	if (!N) {
		cout << "1\n";
		return;
	}

	cout << power(2LL, N - 1LL) << '\n';
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
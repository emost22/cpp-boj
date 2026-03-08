#include <iostream>
using namespace std;
typedef long long ll;

ll N;

ll nCr(ll n, ll r) {
	ll ret = 1LL;
	for (ll i = n; i > n - r; i--) {
		ret *= i;
	}

	for (ll i = r; i > 1LL; i--) {
		ret /= i;
	}

	return ret;
}

void func() {
	cout << nCr(N, 5LL) << '\n';
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
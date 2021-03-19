#include <iostream>
using namespace std;
typedef long long ll;

ll ans[10], N;

void calc(ll x, ll mul) {
	while (x) {
		ans[x % 10] += mul;
		x /= 10;
	}
}

void func(ll l, ll r, ll mul) {
	while (l % 10 != 0 && l <= r) {
		calc(l, mul);
		l++;
	}
	while (r % 10 != 9 && l <= r) {
		calc(r, mul);
		r--;
	}
	if (l > r) return;

	ll tmp = (r / 10 - l / 10 + 1)*mul;
	for (int i = 0; i < 10; i++) {
		ans[i] += tmp;
	}

	func(l / 10, r / 10, mul * 10);
}

void print() {
	for (int i = 0; i < 10; i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	func(1, N, 1);
	print();

	return 0;
}
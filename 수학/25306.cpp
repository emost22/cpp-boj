#include <iostream>
using namespace std;
typedef long long ll;

ll l, r;

void func() {
	ll x = 0;
	while (l < r) {
		x ^= l;
		l++;
		if (!(l % 4LL)) break;
	}

	while (l <= r) {
		x ^= r;
		if (!(r % 4LL)) break;
		r--;
	}

	cout << x << '\n';
}

void input() {
	cin >> l >> r;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
#include <iostream>
using namespace std;
typedef long long ll;

ll ax, ay, bx, by;
ll N;

ll getC(ll x, ll r) {
	if (x < r) return 0LL;

	ll ret = 1LL;
	for (ll i = x; i > x - r; i--) {
		ret *= i;
	}

	for (ll i = r; i > 1; i--) {
		ret /= i;
	}

	return ret;
}

void func() {
	ll ret = getC(N + 1LL, 2LL) * getC(N + 1LL, 2LL);

	if (ay == by) {
		if (ax > bx) swap(ax, bx);
		if (0 <= bx && ax < N) {
			ax = max(-1LL, ax);
			bx = min(N, bx);
			ret += (getC(bx - ax, 2LL) * (N + 1LL));
		}
	}
	else if (ax == bx) {
		if (ay > by) swap(ay, by);
		if (0 <= by && ay < N) {
			ay = max(-1LL, ay);
			by = min(N, by);
			ret += (getC(by - ay, 2LL) * (N + 1LL));
		}
	}

	cout << ret << '\n';
}

void input() {
	cin >> N >> ax >> ay >> bx >> by;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
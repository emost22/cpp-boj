#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

ll N;

void func() {
	ll l = sqrt(N);
	ll r = sqrt((1LL << 63) - 1);
	ll ans = -1;
	while (l <= r) {
		ll m = (l + r) / 2LL;

		if (m * m >= N) {
			ans = m;
			r = m - 1;
		}
		else {
			l = m + 1;
		}
	}

	if (ans == -1) ans = r + 1;
	cout << ans << '\n';
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
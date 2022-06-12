#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;
typedef long long ll;

ll list[MAX];
int N;

ll getDis(ll x) {
	ll ret = 0;
	for (int i = 1; i < N; i++) {
		ret += abs(x * (ll)i - list[i]);
	}

	return ret;
}

void func() {
	ll l = 0;
	ll r = list[N - 1];
	while (r - l >= 3LL) {
		ll p = (l * 2LL + r) / 3LL;
		ll q = (l + r * 2LL) / 3LL;

		if (getDis(p) < getDis(q)) {
			r = q;
		}
		else {
			l = p;
		}
	}

	ll ans = 1e18;
	for (ll i = l; i <= r; i++) {
		ans = min(ans, getDis(i));
	}

	cout << ans << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
#include <iostream>
using namespace std;
typedef long long ll;

ll N;

void func() {
	ll ex = N * (N + 1) >> 1;

	ll l = 1;
	ll r = N;
	int ret = 1;
	while (l <= r) {
		ll m = (l + r) >> 1;

		if ((m - 1) * m <= ex) {
			ret = m;
			l = m + 1;
		}
		else {
			r = m - 1;
		}
	}

	cout << ret << '\n';
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
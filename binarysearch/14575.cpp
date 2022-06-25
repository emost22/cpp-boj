#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

pll list[MAX];
ll l, r;
int N, T;

bool chk(ll m) {
	ll sum = 0;
	ll diff = 0;
	for (int i = 0; i < N; i++) {
		if (m < list[i].first) return false;

		sum += list[i].first;
		diff += (min(m, list[i].second) - list[i].first);
	}

	if (sum > T) return false;
	else if (sum + diff >= T) return true;
	else return false;
}

void func() {
	ll ans = -1;
	while (l <= r) {
		ll m = (l + r) / 2;

		if (chk(m)) {
			ans = m;
			r = m - 1;
		}
		else {
			l = m + 1;
		}
	}

	cout << ans << '\n';
}

void input() {
	l = 1e9;
	cin >> N >> T;
	for (int i = 0; i < N; i++) {
		cin >> list[i].first >> list[i].second;
		l = min(l, list[i].first);
		r = max(r, list[i].second);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
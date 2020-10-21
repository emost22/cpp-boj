#include <iostream>
using namespace std;
typedef long long ll;

pair<ll, ll> list[10000];
ll ans;
int N;

ll Abs(ll x) {
	return x > 0 ? x : -x;
}

ll ccw(ll x, ll y, ll x2, ll y2, ll x3, ll y3) {
	ll result = x * (y2 - y3) + x2 * (y3 - y) + x3 * (y - y2);

	return result;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i].first >> list[i].second;
	}

	ll x = list[0].first;
	ll y = list[0].second;
	for (int i = 1; i < N - 1; i++) {
		ll x2 = list[i].first;
		ll y2 = list[i].second;
		ll x3 = list[i + 1].first;
		ll y3 = list[i + 1].second;
		ans += ccw(x, y, x2, y2, x3, y3);
	}

	ans = Abs(ans);
	if (ans % 2) cout << ans / 2 << ".5\n";
	else cout << ans / 2 << ".0\n";

	return 0;
}
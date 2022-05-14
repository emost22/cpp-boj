#include <iostream>
#define MAX 10
using namespace std;
typedef long long ll;

ll cnt[MAX];
ll N;

ll getDigit(ll x) {
	ll ret = 0;
	while (x) {
		ret++;
		x /= 10;
	}

	return ret;
}

void func() {
	ll digit = getDigit(N);
	ll ans = 0;
	ll tmp = 9;
	for (int i = 1; i < digit; i++) {
		ans += cnt[i];
		tmp = tmp * 10LL + 9LL;
	}

	ans += (digit * (cnt[digit] / digit - (tmp - N)));

	cout << ans << '\n';
}

void init() {
	ll mul = 9;
	for (ll i = 1; i < MAX; i++) {
		cnt[i] = i * mul;
		mul *= 10LL;
	}
}

void input() {
	cin >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	input();
	func();

	return 0;
}
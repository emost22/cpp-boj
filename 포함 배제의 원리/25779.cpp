#include <iostream>
#define MAX 17
using namespace std;
typedef long long ll;

ll list[MAX];
ll N;
int K;

ll getThNumber(ll x) {
	ll ret = 0;
	for (int i = 1; i < (1 << K); i++) {
		int cnt = 0;
		ll tmp = 1LL;
		for (int j = 0; j < K; j++) {
			if (!(i & (1 << j))) continue;
			cnt++;
			tmp *= list[j];
			if (tmp > x) break;
		}

		if (cnt & 1) ret += (x / tmp);
		else ret -= (x / tmp);
	}
	return x - ret;
}

void func() {
	ll l = 1;
	ll r = 1e18;
	while (l < r) {
		ll m = (l + r) >> 1;
		if (getThNumber(m) >= N) r = m;
		else l = m + 1;
	}
	cout << r << '\n';
}

void input() {
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
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
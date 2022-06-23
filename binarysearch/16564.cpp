#include <iostream>
#include <algorithm>
#define MAX 1000001
using namespace std;
typedef long long ll;

ll list[MAX], K, l, r;
int N;

void func() {
	r += K;
	ll ans = 0;
	while (l <= r) {
		ll m = (l + r) / 2;

		ll sum = 0;
		for (int i = 0; i < N; i++) {
			if (m <= list[i]) continue;
			sum += (m - list[i]);
		}

		if (sum <= K) {
			ans = m;
			l = m + 1;
		}
		else {
			r = m - 1;
		}
	}

	cout << ans << '\n';
}

void input() {
	l = 1e9;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
		l = min(l, list[i]);
		r = max(r, list[i]);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
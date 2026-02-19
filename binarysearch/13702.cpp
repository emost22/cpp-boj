#include <iostream>
#include <algorithm>
#define MAX 10000
using namespace std;
typedef long long ll;

int list[MAX];
int N, K, mx;

void func() {
	ll ret = 0;
	ll l = 1;
	ll r = mx;
	while (l <= r) {
		ll m = (l + r) >> 1;

		int sum = 0;
		for (int i = 0; i < N; i++) {
			sum += (list[i] / m);
		}

		if (sum >= K) {
			ret = m;
			l = m + 1LL;
		}
		else {
			r = m - 1LL;
		}
	}

	cout << ret << '\n';
}

void input() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
		mx = max(mx, list[i]);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
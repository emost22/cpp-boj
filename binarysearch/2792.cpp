#include <iostream>
#include <algorithm>
#define MAX 300001
using namespace std;
typedef long long ll;

ll list[MAX];
ll maxValue;
int N, M;

void func() {
	ll l = 1;
	ll r = maxValue;
	ll ans = 0;
	while (l <= r) {
		ll m = (l + r) / 2;

		ll sum = 0;
		for (int i = 0; i < M; i++) {
			sum += (list[i] / m);
			if (list[i] % m) sum++;
		}

		if (sum <= N) {
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
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> list[i];
		maxValue = max(maxValue, list[i]);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
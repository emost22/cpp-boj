#include <iostream>
#include <algorithm>
#define MAX 1000001
using namespace std;
typedef long long ll;

ll list[MAX], maxTime;
int N, M;

void func() {
	ll l = 1;
	ll r = maxTime * M;
	ll ans = 0;
	while (l <= r) {
		ll m = (l + r) / 2;

		ll sum = 0;
		for (int i = 0; i < N; i++) {
			sum += (m / list[i]);
		}

		if (sum >= M) {
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
	for (int i = 0; i < N; i++) {
		cin >> list[i];
		maxTime = max(maxTime, list[i]);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
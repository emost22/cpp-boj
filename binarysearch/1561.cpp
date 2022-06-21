#include <iostream>
#include <algorithm>
#define MAX 10001
using namespace std;
typedef long long ll;

ll list[MAX];
ll N, maxTime;
int M;

ll searching() {
	ll l = 0;
	ll r = maxTime * N;
	ll t = 0;
	while (l <= r) {
		ll m = (l + r) / 2;

		ll sum = M;
		for (int i = 0; i < M; i++) {
			sum += (m / list[i]);
		}

		if (sum >= N) {
			t = m;
			r = m - 1;
		}
		else {
			l = m + 1;
		}
	}

	return t;
}

void func() {
	if (N <= M) {
		cout << N << '\n';
		return;
	}

	ll t = searching();
	ll ans = M;
	for (int i = 0; i < M; i++) {
		ans += ((t - 1) / list[i]);
	}

	for (int i = 0; i < M; i++) {
		if (!(t % list[i])) ans++;

		if (ans == N) {
			cout << i + 1 << '\n';
			return;
		}
	}
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
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
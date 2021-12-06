#include <iostream>
#define MAX 1000000
using namespace std;
typedef long long ll;

ll list[MAX];
ll N;

void func() {
	ll ans = 0;
	ll x = 1;
	while (x < MAX) {
		ll cnt = 0;
		for (int i = 0; i < N; i++) {
			if (list[i] & x) cnt++;
		}

		ans += (N - cnt) * cnt * x;

		x <<= 1;
	}

	cout << ans << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
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
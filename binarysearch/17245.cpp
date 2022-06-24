#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;
typedef long long ll;

ll list[MAX][MAX], cnt;
int N;

void func() {
	ll l = 0;
	ll r = 1e7;
	ll ans = 0;
	while (l <= r) {
		ll m = (l + r) / 2LL;

		ll sum = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				sum += min(m, list[i][j]);
			}
		}

		if (sum * 2 >= cnt) {
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
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> list[i][j];
			cnt += list[i][j];
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll list[6];
int chk[6] = { 5,4,3,2,1,0 };
ll x, y, z;
ll N;

void func() {
	if (N == 1) {
		ll ans = 0;
		ll maxValue = 0;
		for (int i = 0; i < 6; i++) {
			ans += list[i];
			maxValue = max(maxValue, list[i]);
		}

		cout << ans - maxValue << '\n';
		return;
	}

	x = 51;
	y = 101;
	z = 151;

	for (int i = 0; i < 6; i++) {
		x = min(x, list[i]);
	}

	for (int i = 0; i < 5; i++) {
		for (int j = i + 1; j < 6; j++) {
			if (j == chk[i]) continue;
			y = min(y, list[i] + list[j]);
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = i + 1; j < 5; j++) {
			if (j == chk[i]) continue;
			for (int k = j + 1; k < 6; k++) {
				if (k == chk[i] || k == chk[j]) continue;

				z = min(z, list[i] + list[j] + list[k]);
			}
		}
	}

	ll a = x * ((N - 2) * (N - 2) + (N - 2) * (N - 1) * 4);
	ll b = y * ((N - 2) * 4 + (N - 1) * 4);
	ll c = z * 4;

	cout << a + b + c << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < 6; i++) {
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
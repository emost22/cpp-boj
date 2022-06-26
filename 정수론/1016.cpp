#include <iostream>
#include <cmath>
#define MAX 1000001
using namespace std;
typedef long long ll;

int flag[MAX];
ll l, r;

void func() {
	for (ll i = 2; i <= sqrt(r); i++) {
		for (ll j = l / (i * i); i * i * j <= r; j++) {
			if (i * i * j < l) continue;

			flag[i * i * j - l] = 1;
		}
	}

	int ans = 0;
	for (int i = 0; i < r - l + 1; i++) {
		ans += (1 - flag[i]);
	}

	cout << ans << '\n';
}

void input() {
	cin >> l >> r;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
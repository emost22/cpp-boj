#include <iostream>
using namespace std;
typedef long long ll;

ll N, K;

void func() {
	ll ans = 0;
	for (int i = 0, j = 0; j < 32; i++, j++) {
		while ((1LL << i) & N) i++;

		if ((1LL << j) & K) ans += (1LL << i);
	}

	cout << ans << '\n';
}

void input() {
	cin >> N >> K;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
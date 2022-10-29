#include <iostream>
#include <algorithm>
using namespace std;

int x, l, r;

void func() {
	int diff = 1e9;
	int ans = 0;
	for (int i = l; i <= r; i++) {
		if (diff > abs(x - i)) {
			ans = i;
			diff = abs(x - i);
		}
	}

	cout << ans << '\n';
}

void input() {
	cin >> x >> l >> r;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
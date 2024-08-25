#include <iostream>
#include <algorithm>
using namespace std;

int l, r, k;

void func() {
	if (k == 2) {
		cout << max(0, r - max(l, 3) + 1) << '\n';
	}
	else if (k == 3) {
		cout << max(0, r / 3 - (max(l, 6) - 1) / 3) << '\n';
	}
	else if (k == 4) {
		cout << max(0, r / 2 - (max(l, 14) - 1) / 2) + (l <= 10 && 10 <= r) << '\n';
	}
	else {
		cout << max(0, r / 5 - (max(l, 15) - 1) / 5) << '\n';
	}
}

void input() {
	cin >> l >> r >> k;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
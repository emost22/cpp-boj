#include <iostream>
using namespace std;

int x, k;

void func() {
	if (!k) {
		cout << x << '\n';
		return;
	}

	int y = 1;
	while (--k) {
		y *= 10;
	}
	
	int tmp = x % (y * 10);
	if (tmp >= 5 * y) {
		cout << x - tmp + y * 10 << '\n';
	}
	else {
		cout << x - tmp << '\n';
	}
}

void input() {
	cin >> x >> k;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
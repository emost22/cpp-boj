#include <iostream>
using namespace std;

int x, y;

void func() {
	int a = 100 - x;
	int b = 100 - y;

	int c = 100 - (a + b);
	int d = a * b;

	cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << d / 100 << ' ' << d % 100 << '\n';
	if (d / 100) {
		c += (d / 100);
		d %= 100;
	}

	cout << c << ' ' << d << '\n';
}

void input() {
	cin >> x >> y;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
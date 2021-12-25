#include <iostream>
using namespace std;

int g, l;

int gcd(int x, int y) {
	return y ? gcd(y, x % y) : x;
}

void func() {
	int xy = l / g;
	int x = 1;
	for (int i = 2; i * i <= xy; i++) {
		if (!(xy % i) && gcd(i, xy / i) == 1) {
			x = i;
		}
	}

	cout << g * x << ' ' << g * (xy / x) << '\n';
}

void input() {
	cin >> g >> l;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
#include <iostream>
#include <cmath>
using namespace std;

double a, b, c;

double getShortLine(double x, double y) {
	return sqrt(y * y - x * x);
}

double getLongLine(double x, double y) {
	return sqrt(y * y + x * x);
}

void func(int tc) {
	if (tc > 1) cout << '\n';
	cout << fixed;
	cout.precision(3);

	cout << "Triangle #" << tc << '\n';
	if (c > 0.0 && (c <= a || c <= b)) {
		cout << "Impossible.\n";
		return;
	}

	if (a < 0.0) {
		cout << "a = " << getShortLine(b, c) << '\n';
	}
	else if (b < 0.0) {
		cout << "b = " << getShortLine(a, c) << '\n';
	}
	else {
		cout << "c = " << getLongLine(a, b) << '\n';
	}
}

void input() {
	cin >> a >> b >> c;

	if (a == 0.0 && b == 0.0 && c == 0.0) exit(0);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	for (int t = 1; ; t++) {
		input();
		func(t);
	}

	return 0;
}
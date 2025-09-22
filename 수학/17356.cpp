#include <iostream>
#include <cmath>
using namespace std;

double a, b;

void func() {
	cout << fixed;
	cout.precision(5);

	cout << 1.0 / (1.0 + pow(10.0, (b - a) / 400.0)) << '\n';
}

void input() {
	cin >> a >> b;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
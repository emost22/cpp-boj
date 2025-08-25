#include <iostream>
#include <cmath>
using namespace std;

double x;

void func() {
	cout << fixed;
	cout.precision(7);

	cout << sqrt(x) * 4.0 << '\n';
}

void input() {
	cin >> x;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
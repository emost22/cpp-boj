#include <iostream>
#include <cmath>
using namespace std;

double K, D1, D2;

void func() {
	cout << fixed;
	cout.precision(7);

	double tmp = (D1 - D2) / 2.0;
	cout << K * K - tmp * tmp << '\n';
}

void input() {
	cin >> K >> D1 >> D2;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
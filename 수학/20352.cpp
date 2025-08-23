#include <iostream>
#include <cmath>
#define PI 3.1415926535897932384626433832795028
using namespace std;

double x;

void func() {
	cout << fixed;
	cout.precision(7);

	cout << 2 * sqrt(x * PI) << '\n';
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
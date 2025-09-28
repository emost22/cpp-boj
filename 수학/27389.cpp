#include <iostream>
using namespace std;

double x;

void func() {
	cout << fixed;
	cout.precision(2);

	cout << x / 4.0 << '\n';
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
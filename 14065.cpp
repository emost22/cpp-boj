#include <iostream>
#define HKM 62.1371192237334
#define GLN 3.785411784
using namespace std;

double x;

void func() {
	cout << fixed;
	cout.precision(7);

	cout << GLN * HKM / x << '\n';
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
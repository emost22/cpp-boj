#include <iostream>
using namespace std;

double ab, bc, cd;

void func() {
	cout << fixed; cout.precision(7);
	cout << ab * cd / bc << '\n';
}

void input() {
	cin >> ab >> bc >> cd;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
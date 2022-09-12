#include <iostream>
#include <algorithm>
using namespace std;

double a, b, c;

void func() {
	cout << (int)max(a * b / c, a / b * c) << '\n';
}

void input() {
	cin >> a >> b >> c;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
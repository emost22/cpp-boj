#include <iostream>
using namespace std;

int x, y;

void func() {
	cout << (x > y ? 'A' : x < y ? 'B' : 'T') << '\n';
}

void input() {
	int a, b, c;
	cin >> a >> b >> c;
	x = a * 3 + b * 2 + c;

	cin >> a >> b >> c;
	y = a * 3 + b * 2 + c;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
#include <iostream>
using namespace std;

int a, b, c;

void func() {
	cout << a * b + c << '\n';
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
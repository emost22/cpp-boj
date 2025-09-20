#include <iostream>
using namespace std;

int x;

void func() {
	cout << x * 10 / 11 << '\n';
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
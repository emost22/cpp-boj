#include <iostream>
#define BAN 3
using namespace std;

int x, y;

void func() {
	cout << x + y + BAN << '\n';
}

void input() {
	cin >> x >> y;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
#include <iostream>
#define BAG (4840 * 5)
using namespace std;

int x, y;

void func() {
	int a = x * y;
	cout << a / BAG + (a % BAG != 0) << '\n';
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
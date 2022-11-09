#include <iostream>
using namespace std;

int x, y;

void func() {
	if (x > y) cout << x + y << '\n';
	else cout << y - x << '\n';
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
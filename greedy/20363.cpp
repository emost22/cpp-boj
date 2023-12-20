#include <iostream>
#include <algorithm>
using namespace std;

int x, y;

void func() {
	cout << x + y + min(x, y) / 10 << '\n';
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
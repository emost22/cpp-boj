#include <iostream>
using namespace std;

int x, y, z;

void func() {
	if (x + y >= 2 * z) cout << (x + y) - z * 2 << '\n';
	else cout << (x + y) << '\n';
}

void input() {
	cin >> x >> y >> z;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
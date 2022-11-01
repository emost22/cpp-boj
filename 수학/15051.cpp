#include <iostream>
#include <algorithm>
using namespace std;

int x, y, z;

void func() {
	cout << min(x * 4 + y * 2, min(x * 2 + z * 2, y * 2 + z * 4)) << '\n';
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
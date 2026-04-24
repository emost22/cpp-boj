#include <iostream>
#include <algorithm>
using namespace std;

int y, c, p;

void func() {
	cout << min(c >> 1, min(y, p)) << '\n';
}

void input() {
	cin >> y >> c >> p;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
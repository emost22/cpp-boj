#include <iostream>
using namespace std;

int x, y, z;

void func() {
	if (x + y <= z) cout << "1\n";
	else cout << "0\n";
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
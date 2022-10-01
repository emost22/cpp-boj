#include <iostream>
using namespace std;

int x, y, z;

void func() {
	int sum = x + y * 2 + z * 3;

	cout << (sum >= 10 ? "happy\n" : "sad\n");
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
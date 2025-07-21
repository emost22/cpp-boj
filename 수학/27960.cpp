#include <iostream>
using namespace std;

int a, b;

void func() {
	cout << (a ^ b) << '\n';
}

void input() {
	cin >> a >> b;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
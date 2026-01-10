#include <iostream>
using namespace std;

int a;

void func() {
	cout << a / 5 << '\n';
}

void input() {
	cin >> a;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
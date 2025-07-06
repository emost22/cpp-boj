#include <iostream>
using namespace std;

int a, b, c;

void func() {
	if (a + b == c) cout << "correct!\n";
	else cout << "wrong!\n";
}

void input() {
	cin >> a >> b >> c;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
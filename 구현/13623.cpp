#include <iostream>
using namespace std;

int a, b, c;

void func() {
	if (a == b && b == c) cout << "*\n";
	else if (a == b && b != c) cout << "C\n";
	else if (a == c && a != b) cout << "B\n";
	else if (b == c && a != b) cout << "A\n";
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
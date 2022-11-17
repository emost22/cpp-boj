#include <iostream>
using namespace std;

int a, b, c;

bool isPlus() {
	return (a + b == c) || (a + c == b) || (b + c == a);
}

bool isMultiple() {
	return (a * b == c) || (a * c == b) || (b * c == a);
}

void func() {
	if (isPlus()) cout << "1\n";
	else if (isMultiple()) cout << "2\n";
	else cout << "3\n";
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
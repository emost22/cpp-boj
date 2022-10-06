#include <iostream>
using namespace std;

int x, y, z;
char op;

int calc() {
	if (op == '+') {
		return x + y;
	}
	else if (op == '-') {
		return x - y;
	}
	else if (op == '*') {
		return x * y;
	}
	else if (op == '/') {
		return x / y;
	}
	else {
		return x % y;
	}
}

void func() {
	cout << (calc() == z ? "YES\n" : "NO\n");
}

void input() {
	char ch;
	cin >> x >> op >> y >> ch >> z;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
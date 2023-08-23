#include <iostream>
#include <string>
using namespace std;

string c;
int a, b;

void func() {
	if ((c[c.size() - 1] - '0') % 2) {
		cout << (a ^ b) << '\n';
	}
	else {
		cout << a << '\n';
	}
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
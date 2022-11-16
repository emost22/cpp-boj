#include <iostream>
#include <string>
using namespace std;

string str[2] = { ":fan::fan::fan:" };

void func() {
	cout << str[0] << '\n' << str[1] << '\n' << str[0] << '\n';
}

void input() {
	string x;
	cin >> x;
	str[1] = ":fan::" + x + "::fan:";
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
#include <iostream>
#include <string>
using namespace std;

string str;

void func() {
	str += "??!";
	cout << str << '\n';
}

void input() {
	cin >> str;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
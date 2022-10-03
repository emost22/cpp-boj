#include <iostream>
#include <string>
using namespace std;

string str;

char toUpper(char x) {
	return x - 32;
}

void func() {
	int len = str.size();
	for (int i = 0; i < len; i++) {
		cout << toUpper(str[i]);
	}
	cout << '\n';
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
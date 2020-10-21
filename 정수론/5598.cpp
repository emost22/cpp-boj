#include <iostream>
#include <string>
using namespace std;

string str;
char ch[26];

void init() {
	for (int i = 3; i < 26; i++) {
		ch[i] = 62 + i;
	}
	ch[0] = 'X';
	ch[1] = 'Y';
	ch[2] = 'Z';
}

int main() {
	init();

	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		cout << ch[str[i] - 65];
	}
	cout << '\n';

	return 0;
}
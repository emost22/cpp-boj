#include <iostream>
#include <string>
using namespace std;

string str;
int len;

bool isVowel(char x) {
	return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u';
}

void func() {
	for (int i = 0; i < len; i++) {
		if (isVowel(str[0])) break;
		str = str.substr(1) + str[0];
	}

	cout << str + "ay\n";
}

void input() {
	cin >> str;
	if (str == "#") exit(0);
	len = str.size();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (1) {
		input();
		func();
	}

	return 0;
}
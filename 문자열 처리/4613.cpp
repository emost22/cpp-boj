#include <iostream>
#include <string>
using namespace std;

string str;

int getInt(char x) {
	if (x == ' ') return 0;
	else return x - 'A' + 1;
}

void func() {
	int ret = 0;
	int len = str.size();
	for (int i = 0; i < len; i++) {
		ret += ((i + 1) * getInt(str[i]));
	}

	cout << ret << '\n';
}

void input() {
	getline(cin, str);
	if (str == "#") exit(0);
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
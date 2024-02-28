#include <iostream>
#include <string>
using namespace std;

string str;
int len;

void func() {
	int cnt = 0;
	for (int i = 0; i < len; i++) {
		cnt += str[i] == '1';
	}

	if (cnt & 1) {
		if (str[len - 1] == 'e') {
			str[len - 1] = '1';
		}
		else {
			str[len - 1] = '0';
		}
	}
	else {
		if (str[len - 1] == 'e') {
			str[len - 1] = '0';
		}
		else {
			str[len - 1] = '1';
		}
	}

	cout << str << '\n';
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
#include <iostream>
#include <string>
using namespace std;

string str;
int len;

bool isContainAlpha(char x) {
	for (int i = 0; i < len; i++) {
		if (str[i] == x) return true;
	}
	return false;
}

void func() {
	char r;
	if (isContainAlpha('A')) {
		r = 'A';
	}
	else if (isContainAlpha('B')) {
		r = 'B';
	}
	else if (isContainAlpha('C')) {
		r = 'C';
	}
	else {
		for (int i = 0; i < len; i++) {
			cout << 'A';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < len; i++) {
		if (str[i] == 'B' || str[i] == 'C' || str[i] == 'D' || str[i] == 'F') {
			str[i] = r;
		}
	}

	cout << str << '\n';
}

void input() {
	cin >> str;
	len = str.size();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
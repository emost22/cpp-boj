#include <iostream>
#include <string>
using namespace std;

string str;
int len;

void func() {
	if (len <= 2) {
		cout << "CE\n";
		return;
	}

	if (str[0] != '\"' || str[len - 1] != '\"') {
		cout << "CE\n";
		return;
	}

	cout << str.substr(1, len - 2) << '\n';
}

void input() {
	getline(cin, str);
	len = str.size();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
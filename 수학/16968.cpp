#include <iostream>
#include <string>
using namespace std;

string str;

void func() {
	int ret = 0;
	if (str[0] == 'd') ret = 10;
	else ret = 26;

	for (int i = 1; i < str.size(); i++) {
		if (str[i] == 'd') {
			if (str[i] == str[i - 1]) ret *= 9;
			else ret *= 10;
		}
		else {
			if (str[i] == str[i - 1]) ret *= 25;
			else ret *= 26;
		}
	}
	cout << ret << '\n';
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
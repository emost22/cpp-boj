#include <iostream>
#include <string>
using namespace std;

string str;
int x, y;

void func() {
	if (str[1] == '0') {
		x = 10;
		if (str.size() == 4) {
			y = 10;
		}
		else y = str[2] - '0';
	}
	else {
		x = str[0] - '0';
		if (str.size() == 3) {
			y = 10;
		}
		else y = str[1] - '0';
	}
	cout << x + y << '\n';
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
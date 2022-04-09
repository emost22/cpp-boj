#include <iostream>
#include <string>
using namespace std;

string str;

void func() {
	int len = str.size();
	if (len == 1 || str[0] != '0') {
		cout << str << '\n';
		return;
	}

	int ans = 0;
	int mul, idx;
	if (str[1] == 'x') {
		idx = 2;
		mul = 16;
	}
	else {
		idx = 1;
		mul = 8;
	}

	int tmp = 1;
	for (int i = len - 1; i >= idx; i--) {
		int x = str[i];
		if ('a' <= x && x <= 'f') x -= ('a' - 10);
		else x -= '0';

		ans += (x * tmp);
		tmp *= mul;
	}

	cout << ans << '\n';
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
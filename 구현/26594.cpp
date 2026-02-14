#include <iostream>
#include <string>
using namespace std;

string str;
int len;

void func() {
	int ret = 1;
	for (int i = 1; i < len; i++) {
		if (str[i - 1] != str[i]) break;
		ret++;
	}

	cout << ret << '\n';
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
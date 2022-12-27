#include <iostream>
#include <string>
using namespace std;

string str;
int len;

void func() {
	int ret = 0;
	int num = 0;
	for (int i = 0; i < len; i++) {
		if (str[i] == ',') {
			ret += num;
			num = 0;
		}
		else {
			num = num * 10 + str[i] - '0';
		}
	}

	cout << ret + num << '\n';
}

void input() {
	str = "";
	string tmp;
	while (cin >> tmp) {
		str += tmp;
	}
	len = str.size();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
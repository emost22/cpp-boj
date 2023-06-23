#include <iostream>
#include <string>
using namespace std;

string str;

void func() {
	int ret = 0;
	int f = 0;

	int len = str.size();
	for (int i = 1; i < len; i++) {
		if (str[i - 1] == '(' && str[i - 1] == str[i]) f++;
		else if (str[i - 1] == ')' && str[i - 1] == str[i]) ret += f;
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
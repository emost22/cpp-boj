#include <iostream>
#include <string>
using namespace std;

string str;
int len;

bool isPalindrome(string str) {
	int l = 0;
	int r = len - 1;
	while (l < r) {
		if (str[l++] != str[r--]) return false;
	}

	return true;
}

string getNextNumber(string str) {
	string nstr = to_string(stoi(str) + 1);
	while (nstr.size() < len) {
		nstr = '0' + nstr;
	}
	return nstr;
}

void func() {
	int ret = 0;
	while (1) {
		if (isPalindrome(str)) {
			cout << ret << '\n';
			return;
		}
		ret++;
		str = getNextNumber(str);
	}
}

void input() {
	cin >> str;
	len = str.size();
	if (str == "0") exit(0);
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
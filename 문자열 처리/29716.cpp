#include <iostream>
#include <string>
#define MAX 501
using namespace std;

int list[MAX];
int J, N;

void transNumber(string str) {
	bool flag = false;
	for (auto x : str) {
		if (x == ' ') {
			flag = !flag;
			continue;
		}

		if (flag) N = N * 10 + x - '0';
		else J = J * 10 + x - '0';
	}
}

bool isUppercase(char x) {
	return 'A' <= x && x <= 'Z';
}

bool isLowercase(char x) {
	return 'a' <= x && x <= 'z';
}

bool isNumber(char x) {
	return '0' <= x && x <= '9';
}

int getPsSize(string str) {
	int ret = 0;
	for (auto x : str) {
		if (isUppercase(x)) ret += 4;
		else if (isLowercase(x) || isNumber(x)) ret += 2;
		else ret++;
	}

	return ret;
}

void func() {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		ret += (list[i] <= J);
	}
	cout << ret << '\n';
}

void input() {
	string str;
	getline(cin, str);
	transNumber(str);

	for (int i = 0; i < N; i++) {
		getline(cin, str);
		list[i] = getPsSize(str);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
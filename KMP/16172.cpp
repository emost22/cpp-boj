#include <iostream>
#include <algorithm>
#include <string>
#define MAX 200001
using namespace std;

string tmp, str, pattern;
int failMove[MAX];
int sLen, pLen;

void makeFail() {
	int j = 0;
	for (int i = 1; i < pLen; i++) {
		while (j > 0 && pattern[i] != pattern[j]) {
			j = failMove[j - 1];
		}

		if (pattern[i] == pattern[j]) {
			failMove[i] = ++j;
		}
	}
}

void func() {
	makeFail();

	int j = 0;
	for (int i = 0; i < sLen; i++) {
		while (j > 0 && str[i] != pattern[j]) {
			j = failMove[j - 1];
		}

		if (str[i] == pattern[j]) {
			if (j == pLen - 1) {
				cout << "1\n";
				return;
			}
			else j++;
		}
	}

	cout << "0\n";
}

void init() {
	int n = tmp.size();
	for (int i = 0; i < n; i++) {
		if ('0' <= tmp[i] && tmp[i] <= '9') continue;
		str += tmp[i];
	}
	sLen = str.size();
}

void input() {
	cin >> tmp >> pattern;

	pLen = pattern.size();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	init();
	func();

	return 0;
}
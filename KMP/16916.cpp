#include <iostream>
#include <string>
using namespace std;

string str, pattern;
int failMove[1000001];
int strLength, patternLength;

void func() {
	int j = 0;
	for (int i = 0; i < strLength; i++) {
		while (j > 0 && str[i] != pattern[j]) {
			j = failMove[j - 1];
		}

		if (str[i] == pattern[j]) {
			if (j == patternLength - 1) {
				cout << "1\n";
				return;
			}
			else j++;
		}
	}

	cout << "0\n";
}

void makeFail() {
	int j = 0;
	for (int i = 1; i < patternLength; i++) {
		while (j > 0 && pattern[i] != pattern[j]) {
			j = failMove[j - 1];
		}

		if (pattern[i] == pattern[j]) {
			failMove[i] = ++j;
		}
	}
}

void input() {
	cin >> str >> pattern;

	strLength = str.size();
	patternLength = pattern.size();
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	makeFail();
	func();

	return 0;
}
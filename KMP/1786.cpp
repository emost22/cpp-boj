#include <iostream>
#include <string>
#include <vector>
using namespace std;

string str, pattern;
vector<int> ans;
int failMove[1000001];
int strLength, patternLength;

void print() {
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
}

void func() {
	int j = 0;
	for (int i = 0; i < strLength; i++) {
		while (j > 0 && str[i] != pattern[j]) {
			j = failMove[j - 1];
		}

		if (str[i] == pattern[j]) {
			if (j == patternLength - 1) {
				ans.push_back(i - j + 1);
				j = failMove[j];
			}
			else j++;
		}
	}
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
	getline(cin, str);
	getline(cin, pattern);

	strLength = str.size();
	patternLength = pattern.size();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	makeFail();
	func();
	print();

	return 0;
}
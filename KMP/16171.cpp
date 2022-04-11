#include <iostream>
#include <algorithm>
#include <string>
#define MAX 101
using namespace std;

string str, pattern;
int fail[MAX];
int N, M;

void makeFail() {
	for (int i = 1, j = 0; i < M; i++) {
		while (j > 0 && pattern[i] != pattern[j]) {
			j = fail[j - 1];
		}

		if (pattern[i] == pattern[j]) {
			fail[i] = ++j;
		}
	}
}

void func() {
	makeFail();

	for (int i = 0, j = 0; i < N; i++) {
		while (j > 0 && str[i] != pattern[j]) {
			j = fail[j - 1];
		}

		if (str[i] == pattern[j]) {
			if (j == M - 1) {
				cout << "1\n";
				return;
			}
			j++;
		}
	}

	cout << "0\n";
}

void input() {
	string tmp;
	cin >> tmp >> pattern;
	int n = tmp.size();
	for (int i = 0; i < n; i++) {
		if ('0' <= tmp[i] && tmp[i] <= '9') continue;
		str += tmp[i];
	}

	N = str.size();
	M = pattern.size();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
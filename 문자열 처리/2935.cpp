#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str1, str2;
char op;

void func() {
	if (str1.size() < str2.size()) swap(str1, str2);
	int N = str1.size();
	int M = str2.size();

	if (op == '+') {
		reverse(str1.begin(), str1.end());
		reverse(str2.begin(), str2.end());
		for (int i = 0; i < N; i++) {
			if (i == M) break;

			if (str2[i] == '1') str1[i]++;
		}

		reverse(str1.begin(), str1.end());
	}
	else {
		for (int i = 1; i < M; i++) {
			str1 += '0';
		}
	}

	cout << str1 << '\n';
}

void input() {
	cin >> str1 >> op >> str2;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
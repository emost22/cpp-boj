#include <iostream>
#include <string>
#define LEN 13
using namespace std;

string str;

void func() {
	int d = 1;
	int sum = 0;
	for (int i = 0; i < LEN - 1; i++) {
		if (str[i] == '*') {
			if (i & 1) d = 3;
			continue;
		}

		if (i & 1) sum += ((str[i] - '0') * 3);
		else sum += (str[i] - '0');
	}

	int m = 10 - (str[LEN - 1] - '0');
	if (m == 10) m = 0;
	for (int i = 0; i < 10; i++) {
		if (m == (sum + i * d) % 10) {
			cout << i << '\n';
			return;
		}
	}
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
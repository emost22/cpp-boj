#include <iostream>
#include <string>
using namespace std;

string str;
string pattern = "KOREA";

void func() {
	int len = str.size();
	int plen = pattern.size();
	int idx = 0;
	int ret = 0;
	for (int i = 0; i < len; i++) {
		if (str[i] == pattern[idx]) {
			idx++;
			ret++;
			if (idx == 5) idx = 0;
		}
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
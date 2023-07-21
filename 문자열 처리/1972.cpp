#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

string str;

void func() {
	int len = str.size();
	for (int k = 1; k < len - 1; k++) {
		unordered_set<string> s;
		for (int i = 0; i + k < len; i++) {
			string tmp = "";
			tmp += str[i];
			tmp += str[i + k];
			if (s.find(tmp) != s.end()) {
				cout << str << " is NOT surprising.\n";
				return;
			}
			s.insert(tmp);
		}
	}

	cout << str << " is surprising.\n";
}

void input() {
	cin >> str;
	if (str == "*") exit(0);
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
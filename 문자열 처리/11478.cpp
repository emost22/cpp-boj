#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

unordered_set<string> s;
string str;

void func() {
	int len = str.size();
	string tmp = "";
	for (int i = 0; i < len; i++) {
		tmp = "";
		for (int j = i; j < len; j++) {
			tmp += str[j];

			s.insert(tmp);
		}
	}

	cout << s.size() << '\n';
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
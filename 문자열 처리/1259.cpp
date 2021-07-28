#include <iostream>
#include <string>
using namespace std;

string str;

void func() {
	int l = 0;
	int r = str.size() - 1;
	while (l < r) {
		if (str[l] != str[r]) {
			cout << "no\n";
			return;
		}
		l++;
		r--;
	}

	cout << "yes\n";
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (cin >> str) {
		if (str == "0") return 0;

		func();
	}
}
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string str1, str2;

void func() {
	sort(str1.begin(), str1.end());
	string ans = "-1";
	do {
		if (str1[0] == '0') continue;
		if (stoi(str1) < stoi(str2)) {
			ans = str1;
		}
	} while (next_permutation(str1.begin(), str1.end()));

	cout << ans << '\n';
}

void input() {
	cin >> str1 >> str2;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
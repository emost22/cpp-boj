#include <iostream>
#include <string>
using namespace std;

int diff = 32;
string str;

void func() {
	for (int i = 0; i < str.size(); i++) {
		if ('A' <= str[i] && str[i] <= 'Z') str[i] += diff;
		else str[i] -= diff;
	}

	cout << str << '\n';
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
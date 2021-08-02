#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str;
int mul, ans;

int charToInt(char x) {
	if ('0' <= x && x <= '9') return x - 48;
	else return x - 55;
}

void func() {
	reverse(str.begin(), str.end());

	int x = 1;
	for (int i = 0; i < str.size(); i++) {
		ans += charToInt(str[i]) * x;
		x *= mul;
	}

	cout << ans << '\n';
}

void input() {
	cin >> str >> mul;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
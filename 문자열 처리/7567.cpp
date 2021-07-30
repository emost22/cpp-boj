#include <iostream>
#include <string>
using namespace std;

string str;

void func() {
	int ans = 10;
	for (int i = 1; i < str.size(); i++) {
		if (str[i] != str[i - 1]) ans += 10;
		else ans += 5;
	}

	cout << ans << '\n';
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
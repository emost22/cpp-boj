#include <iostream>
#include <string>
using namespace std;

string str;
bool m, o, b, i, s;

void func() {
	for (auto x : str) {
		if (x == 'M') m = true;
		else if (x == 'O') o = true;
		else if (x == 'B') b = true;
		else if (x == 'I') i = true;
		else if (x == 'S') s = true;
	}
	
	cout << ((m && o && b && i && s) ? "YES\n" : "NO\n");
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
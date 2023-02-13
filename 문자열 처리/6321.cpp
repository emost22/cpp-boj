#include <iostream>
#include <string>
using namespace std;

string str;

char getNextAlpha(char x) {
	if (x == 'Z') return 'A';
	else return x + 1;
}

void func(int tc) {
	for (char &x : str) {
		x = getNextAlpha(x);
	}

	cout << "String #" << tc << '\n' << str << '\n';
}

void input() {
	cin >> str;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		input();
		func(t);
		if (t != tc) cout << '\n';
	}

	return 0;
}
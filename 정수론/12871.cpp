#include <iostream>
#include <string>
using namespace std;

string str1, str2;

int gcd(int x, int y) {
	if (!y) return x;
	return gcd(y, x % y);
}

int lcm(int x, int y) {
	return x * y / gcd(x, y);
}

void func() {
	int str1Length = str1.size();
	int str2Length = str2.size();

	int len = lcm(str1Length, str2Length);

	int x = 0;
	int y = 0;
	for (int i = 0; i < len; i++) {
		if (str1[x] != str2[y]) {
			cout << "0\n";
			return;
		}
		x++;
		y++;
		if (x == str1Length) x = 0;
		if (y == str2Length) y = 0;
	}

	cout << "1\n";
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
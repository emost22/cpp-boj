#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string str;
int list[2], idx;

int gcd(int x, int y) {
	if (!y) return x;
	return gcd(y, x % y);
}

void func() {
	string ans;
	istringstream ss(str);
	while (getline(ss, ans, ':')) {
		list[idx++] = stoi(ans);
	}

	int g = gcd(list[0], list[1]);

	cout << list[0] / g << ':' << list[1] / g << '\n';
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
#include <iostream>
#include <string>
using namespace std;

string x, y;

void func() {
	cout << stoll(x) + stoll(y) << '\n';
}

void input() {
	string tmp;
	cin >> x >> tmp;
	x += tmp;
	cin >> y >> tmp;
	y += tmp;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
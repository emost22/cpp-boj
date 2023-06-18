#include <iostream>
#include <algorithm>
using namespace std;

int a, b;

void func() {
	a--;
	b--;
	cout << (abs(a / 4 - b / 4) + abs(a % 4 - b % 4)) << '\n';
}

void input() {
	cin >> a >> b;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
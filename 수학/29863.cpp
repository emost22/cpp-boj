#include <iostream>
#define DAY 24
using namespace std;

int l, r;

void func() {
	if (l > r) r += DAY;
	cout << r - l << '\n';
}

void input() {
	cin >> l >> r;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;

int a, b;

void func() {
	cout << (min(a - 1, b) << 1) + 1 << '\n';
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
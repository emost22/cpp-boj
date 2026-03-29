#include <iostream>
using namespace std;

int l, r;

void func() {
	int ret = 0;
	if (!(l & 1)) {
		ret++;
		l++;
	}

	int x = r - l + 1;
	cout << ret + (x >> 1) + (x & 1) << '\n';
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
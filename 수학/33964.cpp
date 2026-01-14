#include <iostream>
using namespace std;

int x, y;

int getRepunit(int k) {
	int ret = 0;
	while (k--) {
		ret = ret * 10 + 1;
	}

	return ret;
}

void func() {
	cout << getRepunit(x) + getRepunit(y) << '\n';
}

void input() {
	cin >> x >> y;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
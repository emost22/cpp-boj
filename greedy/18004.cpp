#include <iostream>
using namespace std;

int a, b;

void func() {
	int ret = 0;
	while (a > b) {
		if (a & 1) a++;
		else a >>= 1;
		ret++;
	}

	cout << ret + b - a << '\n';
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
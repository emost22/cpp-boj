#include <iostream>
using namespace std;

int x, y;

void func() {
	int a = x / y;
	int r = x - a * y;
	cout << a << ' ' << r << " / " << y << '\n';
}

void input() {
	cin >> x >> y;
	if (!y) exit(0);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (1) {
		input();
		func();
	}

	return 0;
}
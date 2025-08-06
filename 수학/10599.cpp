#include <iostream>
using namespace std;

int a, b, c, d;

void func() {
	cout << c - b << ' ' << d - a << '\n';
}

void input() {
	cin >> a >> b >> c >> d;
	if (!a && !b && !c && !d) exit(0);
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
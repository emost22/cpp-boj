#include <iostream>
using namespace std;

int a, b;

void func() {
	cout << (a << 1) - b << '\n';
}

void input() {
	cin >> a >> b;
	if (!a && !b) exit(0);
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
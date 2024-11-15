#include <iostream>
using namespace std;

int f, s;

void func() {
	int a = f;
	int b = s;
	for (int t = 3; ; t++) {
		int tmp = b;
		b = (a + b) % 10;
		a = tmp;

		if (a == f && b == s) {
			cout << t << '\n';
			return;
		}
	}
}

void input() {
	cin >> f >> s;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
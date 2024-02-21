#include <iostream>
using namespace std;

int a, b;

void func() {
	int l = 0;
	int r = 0;
	while (1) {
		if (a == 1) {
			r += (b - 1);
			break;
		}
		else if (b == 1) {
			l += (a - 1);
			break;
		}

		if (a < b) {
			r += (b / a);
			b %= a;
		}
		else {
			l += (a / b);
			a %= b;
		}
	}

	cout << l << ' ' << r << '\n';
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
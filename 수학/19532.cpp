#include <iostream>
using namespace std;

int a, b, c, d, e, f;

void func() {
	for (int i = -999; i < 1000; i++) {
		for (int j = -999; j < 1000; j++) {
			if (a * i + b * j == c && d * i + e * j == f) {
				cout << i << ' ' << j << '\n';
				return;
			}
		}
	}
}

void input() {
	cin >> a >> b >> c >> d >> e >> f;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
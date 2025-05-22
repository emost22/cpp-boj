#include <iostream>
using namespace std;

int R, B;

void func() {
	for (int i = 3; ; i++) {
		for (int j = 3; j <= i; j++) {
			int b = (i - 2) * (j - 2);
			int r = i * j - b;
			if (r == R && b == B) {
				cout << i << ' ' << j << '\n';
				return;
			}
		}
	}
}

void input() {
	cin >> R >> B;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
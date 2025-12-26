#include <iostream>
using namespace std;

int a[2];

void func() {
	int t = 0;
	while (1) {
		a[1 - t] += a[t];
		if (a[1 - t] >= 5) {
			if (!t) cout << "yt\n";
			else cout << "yj\n";

			return;
		}

		t = 1 - t;
	}
}

void input() {
	cin >> a[0] >> a[1];
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
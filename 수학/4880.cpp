#include <iostream>
using namespace std;

int x, y, z;

void func() {
	if (z - y == y - x) {
		if (x == y && y == z) cout << "GP " << x << '\n';
		else cout << "AP " << z + (z - y) << '\n';
	}
	else {
		cout << "GP " << z * (y / x) << '\n';
	}
}

void input() {
	cin >> x >> y >> z;
	if (!x && !y && !z) exit(0);
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
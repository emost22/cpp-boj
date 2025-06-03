#include <iostream>
#include <algorithm>
using namespace std;

int b, n;

int getSquare(int x, int t) {
	int ret = 1;
	while (t--) {
		ret *= x;
	}
	return ret;
}

void func() {
	int ret = 1;
	int diff = 1e9;
	for (int x = 1; ; x++) {
		int tmp = getSquare(x, n);
		if (diff > abs(tmp - b)) {
			diff = abs(tmp - b);
			ret = x;
		}

		if (tmp > b) break;
	}
	cout << ret << '\n';
}

void input() {
	cin >> b >> n;
	if (!b && !n) exit(0);
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
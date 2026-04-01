#include <iostream>
#include <algorithm>
using namespace std;

int l, r, x;

int getSum(int a) {
	int ret = 0;
	while (a) {
		ret += (a % 10);
		a /= 10;
	}

	return ret;
}

void func() {
	int mn = 1e9;
	int mx = 0;
	for (int i = l; i <= r; i++) {
		int s = getSum(i);
		if (s != x) continue;

		mn = min(mn, i);
		mx = max(mx, i);
	}

	cout << mn << '\n' << mx << '\n';
}

void input() {
	cin >> l >> r >> x;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
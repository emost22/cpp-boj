#include <iostream>
using namespace std;

long long X, Y, Z;
long long ans;

void binarysearch(long long s, long long e) {
	if (s > e) return;
	long long x, y;

	y = (s + e) / 2;
	x = X + y - Y;

	if (Z < 100 * y / x) {
		ans = y - Y;
		binarysearch(s, y - 1);
	}
	else {
		binarysearch(y + 1, e);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> X >> Y;
	Z = 100 * Y / X;
	if (Z == 100 || Z == 99) {
		cout << "-1\n";
		return 0;
	}

	binarysearch(Y, 10000000000);

	cout << ans << '\n';

	return 0;
}
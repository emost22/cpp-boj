#include <iostream>
using namespace std;

int x, y, k;

void func(int tc) {
	cout << "Data set: " << x << ' ' << y << ' ' << k << '\n';

	int nx = x;
	int ny = y;
	while (k--) {
		if (nx > ny) nx >>= 1;
		else ny >>= 1;
	}
	if (nx < ny) swap(nx, ny);

	cout << nx << ' ' << ny << '\n';
	if (tc) cout << '\n';
}

void input() {
	cin >> x >> y >> k;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func(tc);
	}

	return 0;
}
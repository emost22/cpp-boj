#include <iostream>
#include <algorithm>
using namespace std;

int N, M, x, y;

void func() {
	int ans = 0;
	if (x < 6 * y) ans += (x * (N / 6));
	else ans += (6 * y * (N / 6));
	N %= 6;

	if (N) {
		if (x < N * y) ans += x;
		else ans += (N * y);
	}

	cout << ans << '\n';
}

void input() {
	x = 1e9;
	y = 1e9;
	int a, b;
	cin >> N >> M;
	while (M--) {
		cin >> a >> b;
		x = min(x, a);
		y = min(y, b);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
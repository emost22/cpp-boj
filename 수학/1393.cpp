#include <iostream>
using namespace std;

int sx, sy, ex, ey, dx, dy;

int gcd(int x, int y) {
	return y ? gcd(y, x % y) : x;
}

int getDis(int x, int y) {
	return (ex - x) * (ex - x) + (ey - y) * (ey - y);
}

void func() {
	int g = gcd(dx, dy);
	dx /= g;
	dy /= g;

	int x = sx;
	int y = sy;
	int dis = getDis(sx, sy);
	while (1) {
		x += dx;
		y += dy;

		int d = getDis(x, y);
		if (dis < d) {
			cout << x - dx << ' ' << y - dy << '\n';
			return;
		}

		dis = d;
	}
}

void input() {
	cin >> ex >> ey >> sx >> sy >> dx >> dy;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
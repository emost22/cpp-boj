#include <iostream>
using namespace std;

typedef struct Point {
	int y, m, d;
}Point;

Point a, b;

void func() {
	int x, y, z;
	x = b.y - a.y - (a.m > b.m ? 1 : a.m == b.m ? a.d > b.d ? 1 : 0 : 0);
	y = b.y - a.y + 1;
	z = b.y - a.y;

	cout << x << '\n' << y << '\n' << z << '\n';
}

void input() {
	cin >> a.y >> a.m >> a.d >> b.y >> b.m >> b.d;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
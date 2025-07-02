#include <iostream>
#include <algorithm>
using namespace std;

int bx, by, dx, dy, jx, jy;

void func() {
	int bj = max(abs(bx - jx), abs(by - jy));
	int dj = abs(dx - jx) + abs(dy - jy);

	if (bj < dj) cout << "bessie\n";
	else if (bj > dj) cout << "daisy\n";
	else cout << "tie\n";
}

void input() {
	cin >> bx >> by >> dx >> dy >> jx >> jy;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
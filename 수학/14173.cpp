#include <iostream>
#include <algorithm>
using namespace std;

int sx1, sy1, ex1, ey1, sx2, sy2, ex2, ey2;

void func() {
	int x = max(ex1, ex2) - min(sx1, sx2);
	int y = max(ey1, ey2) - min(sy1, sy2);

	int ret = max(x, y);
	cout << ret * ret << '\n';
}

void input() {
	cin >> sx1 >> sy1 >> ex1 >> ey1 >> sx2 >> sy2 >> ex2 >> ey2;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
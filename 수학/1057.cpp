#include <iostream>
using namespace std;

int N, x, y;

void func() {
	int ret = 0;
	while (x != y) {
		ret++;
		x = (x + 1) >> 1;
		y = (y + 1) >> 1;
	}
	cout << ret << '\n';
}

void input() {
	cin >> N >> x >> y;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
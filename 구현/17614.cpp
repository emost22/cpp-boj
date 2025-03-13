#include <iostream>
using namespace std;

int N;

int getClap(int x) {
	int ret = 0;
	while (x) {
		int y = x % 10;
		if (y == 3 || y == 6 || y == 9) ret++;
		x /= 10;
	}
	return ret;
}

void func() {
	int ret = 0;
	for (int i = 3; i <= N; i++) {
		ret += getClap(i);
	}
	cout << ret << '\n';
}

void input() {
	cin >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
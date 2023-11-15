#include <iostream>
using namespace std;

int x, y, z;

void func() {
	int tmp = x + y;
	int ret = 0;
	while (1) {
		int diff = tmp / z;
		if (!diff) break;

		ret += diff;
		tmp -= (diff * z);
		tmp += diff;
	}

	cout << ret << '\n';
}

void input() {
	cin >> x >> y >> z;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
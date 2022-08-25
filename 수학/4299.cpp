#include <iostream>
#include <algorithm>
using namespace std;

int x, y;

void func() {
	if ((x + y) % 2 || (x - y) % 2) cout << "-1\n";
	else {
		int ret1 = (x + y) / 2;
		int ret2 = (x - y) / 2;
		if (ret1 >= 0 && ret2 >= 0) {
			cout << max(ret1, ret2) << ' ' << min(ret1, ret2) << '\n';
		}
		else {
			cout << "-1\n";
		}
	}
}

void input() {
	cin >> x >> y;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
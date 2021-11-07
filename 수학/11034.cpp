#include <iostream>
#include <algorithm>
using namespace std;

int x, y, z;

void func() {
	cout << max(y - x - 1, z - y - 1) << '\n';
}

void input() {
	cin >> y >> z;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (cin >> x) {
		input();
		func();
	}

	return 0;
}
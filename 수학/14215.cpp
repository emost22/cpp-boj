#include <iostream>
#include <algorithm>
using namespace std;

int list[3];

void func() {
	sort(list, list + 3);

	if (list[0] + list[1] > list[2]) {
		cout << list[0] + list[1] + list[2] << '\n';
	}
	else {
		cout << ((list[0] + list[1]) << 1) - 1 << '\n';
	}
}

void input() {
	cin >> list[0] >> list[1] >> list[2];
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
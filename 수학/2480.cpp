#include <iostream>
#include <algorithm>
using namespace std;

int type, x;
int list[3];

void func() {
	if (type == 1) {
		cout << 10000 + x * 1000 << '\n';
	}
	else if (type == 2) {
		cout << 1000 + x * 100 << '\n';
	}
	else {
		cout << x * 100 << '\n';
	}
}

void input() {
	cin >> list[0] >> list[1] >> list[2];
	if (list[0] == list[1] && list[1] == list[2]) {
		type = 1;
		x = list[0];
	}
	else if (list[0] == list[1] || list[0] == list[2] || list[1] == list[2]) {
		type = 2;
		if (list[0] == list[1] || list[0] == list[2]) x = list[0];
		else x = list[1];
	}
	else {
		type = 3;
		x = max(list[0], max(list[1], list[2]));
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
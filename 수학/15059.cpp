#include <iostream>
using namespace std;

int list[2][3];

void func() {
	int ret = 0;
	for (int i = 0; i < 3; i++) {
		if (list[0][i] >= list[1][i]) continue;
		ret += (list[1][i] - list[0][i]);
	}
	cout << ret << '\n';
}

void input() {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> list[i][j];
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
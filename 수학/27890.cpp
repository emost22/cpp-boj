#include <iostream>
using namespace std;

int x, N;

void func() {
	int nx = x;
	while (N--) {
		if (nx & 1) {
			nx = (nx << 1) ^ 6;
		}
		else {
			nx = (nx >> 1) ^ 6;
		}
	}
	cout << nx << '\n';
}

void input() {
	cin >> x >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
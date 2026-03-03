#include <iostream>
using namespace std;

int N;

void func() {
	int x = 1;
	int y = 1;
	while (1) {
		if (x * y >= N) {
			cout << x << ' ' << y << '\n';
			return;
		}

		if (x < y) x++;
		else y++;
	}
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
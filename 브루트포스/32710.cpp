#include <iostream>
using namespace std;

int N;

void func() {
	if (N < 10) {
		cout << "1\n";
		return;
	}

	for (int i = 2; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			if (i * j == N) {
				cout << "1\n";
				return;
			}
		}
	}
	cout << "0\n";
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
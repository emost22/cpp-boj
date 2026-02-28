#include <iostream>
using namespace std;

int N;

void func() {
	while (1) {
		cout << N << ' ';
		if (N < 10) break;

		int tmp = N;
		int nx = 1;
		while (tmp) {
			nx *= (tmp % 10);
			tmp /= 10;
		}

		N = nx;
	}

	cout << '\n';
}

void input() {
	cin >> N;
	if (!N) exit(0);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (1) {
		input();
		func();
	}

	return 0;
}
#include <iostream>
using namespace std;

int N;

int nCr(int n, int r) {
	int ret = 1;
	for (int i = n; i > n - r; i--) {
		ret *= i;
	}

	for (int i = 2; i <= r; i++) {
		ret /= i;
	}

	return ret;
}

void func() {
	if (N < 4) {
		cout << "0\n";
		return;
	}

	cout << nCr(N - 1, 3) << '\n';
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
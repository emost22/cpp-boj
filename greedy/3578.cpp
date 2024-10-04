#include <iostream>
using namespace std;

int N;

void func() {
	if (!N) {
		cout << "1\n";
		return;
	}

	if (N == 1) {
		cout << "0\n";
		return;
	}

	if (N & 1) {
		N--;
		cout << '4';
	}

	for (int i = 0; i < N; i += 2) {
		cout << '8';
	}
	cout << '\n';
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
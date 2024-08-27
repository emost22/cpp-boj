#include <iostream>
using namespace std;

int N;

void func() {
	if (N == 1) {
		cout << "0\n";
		return;
	}

	cout << ((N * N + 1) >> 1) << '\n';
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
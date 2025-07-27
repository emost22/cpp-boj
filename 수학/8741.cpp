#include <iostream>
using namespace std;

int N;

void func() {
	for (int i = 0; i < N; i++) {
		cout << '1';
	}

	for (int i = 0; i < N - 1; i++) {
		cout << '0';
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
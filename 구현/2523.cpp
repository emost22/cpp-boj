#include <iostream>
using namespace std;

int N;

void func() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			cout << '*';
		}
		cout << '\n';
	}

	for (int i = N - 1; i > 0; i--) {
		for (int j = 1; j <= i; j++) {
			cout << '*';
		}
		cout << '\n';
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	func();

	return 0;
}
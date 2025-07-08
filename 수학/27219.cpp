#include <iostream>
using namespace std;

int N;

void func() {
	while (N >= 5) {
		cout << "V";
		N -= 5;
	}

	while (N--) {
		cout << "I";
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
#include <iostream>
using namespace std;

int N;

void func() {
	if (N & 1) {
		cout << "0\n";
	}
	else if ((N >> 1) & 1) {
		cout << "1\n";
	}
	else {
		cout << "2\n";
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
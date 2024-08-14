#include <iostream>
using namespace std;

int N;

void func() {
	bool isOdd = N & 1;
	while (N > 1) {
		cout << "1 2 ";
		N -= 2;
	}

	if (isOdd) cout << "3\n";
	else cout << '\n';
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
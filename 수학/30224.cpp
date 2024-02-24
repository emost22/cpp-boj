#include <iostream>
using namespace std;

int N;

bool isContainSeven(int x) {
	while (x) {
		if (x % 10 == 7) return true;
		x /= 10;
	}

	return false;
}

bool possibleDivSeven(int x) {
	return x % 7 == 0;
}

void func() {
	bool f1 = isContainSeven(N);
	bool f2 = possibleDivSeven(N);

	if (!f1 && !f2) cout << "0\n";
	else if (!f1 && f2) cout << "1\n";
	else if (f1 && !f2) cout << "2\n";
	else cout << "3\n";
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
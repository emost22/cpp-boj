#include <iostream>
using namespace std;

int x;

void func() {
	if (x % 7 == 2) cout << "1\n";
	else cout << "0\n";
}

void input() {
	cin >> x;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
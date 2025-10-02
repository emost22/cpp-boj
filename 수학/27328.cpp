#include <iostream>
using namespace std;

int a, b;

void func() {
	if (a > b) cout << "1\n";
	else if (a == b) cout << "0\n";
	else cout << "-1\n";
}

void input() {
	cin >> a >> b;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
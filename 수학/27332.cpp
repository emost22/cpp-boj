#include <iostream>
using namespace std;

int a, b;

void func() {
	if (a + 7 * b > 30) cout << "0\n";
	else cout << "1\n";
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
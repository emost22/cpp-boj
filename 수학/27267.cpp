#include <iostream>
using namespace std;

int a, b, c, d;

void func() {
	int m = a * b;
	int p = c * d;

	if (m > p) cout << "M\n";
	else if (m < p) cout << "P\n";
	else cout << "E\n";
}

void input() {
	cin >> a >> b >> c >> d;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
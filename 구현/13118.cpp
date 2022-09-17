#include <iostream>
using namespace std;

int a, b, c, d;
int x, y, r;

void func() {
	if (a == x) cout << "1\n";
	else if (b == x) cout << "2\n";
	else if (c == x) cout << "3\n";
	else if (d == x) cout << "4\n";
	else cout << "0\n";
}

void input() {
	cin >> a >> b >> c >> d >> x >> y >> r;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
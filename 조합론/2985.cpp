#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int a, b, c;
	cin >> a >> b >> c;

	if (a + b == c) cout << a << '+' << b << '=' << c << '\n';
	else if (a - b == c) cout << a << '-' << b << '=' << c << '\n';
	else if (a * b == c) cout << a << '*' << b << '=' << c << '\n';
	else if (b && a / b == c) cout << a << '/' << b << '=' << c << '\n';
	else if (a == b + c) cout << a << '=' << b << '+' << c << '\n';
	else if (a == b - c) cout << a << '=' << b << '-' << c << '\n';
	else if (a == b * c) cout << a << '=' << b << '*' << c << '\n';
	else if (c && a == b / c) cout << a << '=' << b << '/' << c << '\n';

	return 0;
}
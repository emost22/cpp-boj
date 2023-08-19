#include <iostream>
using namespace std;

int a, b;

int gcd(int x, int y) {
	return y ? gcd(y, x % y) : x;
}

int lcm(int x, int y) {
	return x * y / gcd(x, y);
}

void func() {
	cout << lcm(a, b) << ' ' << gcd(a, b) << '\n';
}

void input() {
	cin >> a >> b;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
	}

	return 0;
}
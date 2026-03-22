#include <iostream>
using namespace std;

int x, y;

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

void func() {
	cout << gcd(x, y) << '\n';
}

void input() {
	cin >> x >> y;
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
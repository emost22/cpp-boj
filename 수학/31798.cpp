#include <iostream>
#include <cmath>
using namespace std;

int a, b, c;

void func() {
	if (!c) cout << sqrt(a + b) << '\n';
	else cout << c * c - (a + b) << '\n';
}

void input() {
	cin >> a >> b >> c;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
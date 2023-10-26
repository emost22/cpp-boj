#include <iostream>
#include <algorithm>
using namespace std;

int a, b, c, d, p;

void func() {
	cout << min(a * p, b + max(0, p - c) * d) << '\n';
}

void input() {
	cin >> a >> b >> c >> d >> p;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
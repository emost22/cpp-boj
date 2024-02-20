#include <iostream>
#include <cmath>
using namespace std;

int a, b;

void func() {
	double l = -a - sqrt(a * a - b);
	double r = -a + sqrt(a * a - b);
	if (l == r) {
		cout << l << '\n';
	}
	else {
		cout << l << ' ' << r << '\n';
	}
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
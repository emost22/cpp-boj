#include <iostream>
using namespace std;

int N;

void func() {
	cout << fixed; cout.precision(2);
	double x;
	while (N--) {
		cin >> x;
		x *= 0.8;
		cout << '$' << x << '\n';
	}
}

void input() {
	cin >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
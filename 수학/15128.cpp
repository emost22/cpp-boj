#include <iostream>
using namespace std;

double p1, q1, p2, q2;

void func() {
	double area = p1 / q1 * p2 / q2 / 2.0;
	if (area == (long long)area) cout << "1\n";
	else cout << "0\n";
}

void input() {
	cin >> p1 >> q1 >> p2 >> q2;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
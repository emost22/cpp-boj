#include <iostream>
using namespace std;

int t1, m1, t2, m2;

void func() {
	int m = t2 * 60 + m2 - t1 * 60 - m1;
	if (m < 0) m += (24 * 60);

	cout << m << ' ' << m / 30 << '\n';
}

void input() {
	cin >> t1 >> m1 >> t2 >> m2;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
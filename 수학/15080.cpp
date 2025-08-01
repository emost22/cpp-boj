#include <iostream>
using namespace std;

int h1, m1, s1, h2, m2, s2;

void func() {
	int t1 = h1 * 3600 + m1 * 60 + s1;
	int t2 = h2 * 3600 + m2 * 60 + s2;

	if (t1 > t2) t2 += (24 * 3600);
	cout << t2 - t1 << '\n';
}

void input() {
	char ch;
	cin >> h1 >> ch >> m1 >> ch >> s1 >> h2 >> ch >> m2 >> ch >> s2;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
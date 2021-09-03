#include <iostream>
using namespace std;

int h, m, s;
int dh, dm, ds;
int diff;

void func() {
	s += ds;
	if (s >= 60) {
		s -= 60;
		dm++;
	}

	m += dm;
	if (m >= 60) {
		m -= 60;
		dh++;
	}

	h += dh;
	h %= 24;

	cout << h << ' ' << m << ' ' << s << '\n';
}

void input() {
	cin >> h >> m >> s >> diff;
	dh = diff / 3600;
	diff %= 3600;
	dm = diff / 60;
	ds = diff % 60;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
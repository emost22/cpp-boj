#include <iostream>
using namespace std;

int a, b, c, d;

void func() {
	int ret = 0;
	while (1) {
		if (a == b && b == c && c == d) {
			cout << ret << '\n';
			return;
		}

		int na = abs(a - b);
		int nb = abs(b - c);
		int nc = abs(c - d);
		int nd = abs(d - a);
		a = na;
		b = nb;
		c = nc;
		d = nd;
		ret++;
	}
}

void input() {
	cin >> a >> b >> c >> d;
	if (!a) exit(0);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (1) {
		input();
		func();
	}

	return 0;
}
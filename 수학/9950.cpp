#include <iostream>
using namespace std;

int w, l, a;

void func() {
	if (!w) w = a / l;
	else if (!l) l = a / w;
	else a = w * l;

	cout << w << ' ' << l << ' ' << a << '\n';
}

void input() {
	cin >> w >> l >> a;
	if (!w && !l && !a) exit(0);
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
#include <iostream>
using namespace std;

int a, d, x;

void func() {
	if ((x - a) % d || (x - a) * d < 0) cout << "X\n";
	else cout << (x - a) / d + 1 << '\n';
}

void input() {
	cin >> a >> d >> x;
	if (!a && !d && !x) exit(0);
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
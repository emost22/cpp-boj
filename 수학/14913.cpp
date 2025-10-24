#include <iostream>
using namespace std;

int a, d, k;

void func() {
	if ((k - a) % d || (k - a) / d < 0) cout << "X\n";
	else cout << (k - a) / d + 1 << '\n';
}

void input() {
	cin >> a >> d >> k;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
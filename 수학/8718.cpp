#include <iostream>
using namespace std;

int x, k;

void func() {
	if (7000 * k <= 1000 * x) cout << 7000 * k << '\n';
	else if (3500 * k <= 1000 * x) cout << 3500 * k << '\n';
	else if (1750 * k <= 1000 * x) cout << 1750 * k << '\n';
	else cout << "0\n";
}

void input() {
	cin >> x >> k;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
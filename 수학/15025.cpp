#include <iostream>
#include <algorithm>
using namespace std;

int l, r;

void func() {
	if (!l && !r) {
		cout << "Not a moose\n";
		return;
	}

	if (l == r) cout << "Even " << (l << 1) << '\n';
	else cout << "Odd " << (max(l, r) << 1) << '\n';
}

void input() {
	cin >> l >> r;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
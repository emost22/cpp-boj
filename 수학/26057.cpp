#include <iostream>
using namespace std;

int l, t;

void func() {
	cout << t - (l - t) << '\n';
}

void input() {
	cin >> l >> t;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
#include <iostream>
using namespace std;

int hh, mm;

void func() {
	int ans = mm;
	ans += ((hh - 9) * 60);

	cout << ans << '\n';
}

void input() {
	cin >> hh >> mm;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
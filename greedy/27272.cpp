#include <iostream>
#include <algorithm>
using namespace std;

int a[4];

void func() {
	sort(a, a + 4);
	cout << a[0] * a[1] + a[2] * a[3] << '\n';
}

void input() {
	cin >> a[0] >> a[1] >> a[2] >> a[3];
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
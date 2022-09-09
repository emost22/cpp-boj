#include <iostream>
#include <algorithm>
using namespace std;

int a, b, c, d;

void func() {
	cout << min(a + d, b + c) << '\n';
}

void input() {
	cin >> a >> b >> c >> d;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
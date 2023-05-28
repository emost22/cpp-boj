#include <iostream>
using namespace std;

int x, y;

void func() {
	cout << (x * 100 >= y ? "Yes\n" : "No\n");
}

void input() {
	cin >> x >> y;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
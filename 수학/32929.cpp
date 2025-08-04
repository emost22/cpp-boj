#include <iostream>
#define UOS "UOS"
using namespace std;

int x;

void func() {
	cout << UOS[(x - 1) % 3] << '\n';
}

void input() {
	cin >> x;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
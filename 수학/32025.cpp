#include <iostream>
#include <algorithm>
using namespace std;

int h, w;

void func() {
	cout << min(h, w) * 50 << '\n';
}

void input() {
	cin >> h >> w;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
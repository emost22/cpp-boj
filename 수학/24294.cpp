#include <iostream>
#include <algorithm>
using namespace std;

int w1, h1, w2, h2;

void func() {
	cout << ((max(w1, w2) + 2 + h1 + h2) << 1) << '\n';
}

void input() {
	cin >> w1 >> h1 >> w2 >> h2;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
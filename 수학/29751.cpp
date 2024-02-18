#include <iostream>
using namespace std;

int w, h;

void func() {
	if (w & 1 && h & 1) cout << ((w * h) >> 1) << ".5\n";
	else cout << ((w * h) >> 1) << ".0\n";
}

void input() {
	cin >> w >> h;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
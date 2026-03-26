#include <iostream>
using namespace std;

int w, l, h;

void func() {
	if (w > l) swap(w, l);

	if (w >= (h << 1) && l <= (w << 1)) cout << "good\n";
	else cout << "bad\n";
}

void input() {
	cin >> w >> l >> h;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
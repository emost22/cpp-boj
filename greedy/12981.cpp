#include <iostream>
#include <algorithm>
using namespace std;

int r, g, b;

void func() {
	int ret = min(r, min(g, b));
	r -= ret;
	g -= ret;
	b -= ret;
	
	ret += (r / 3);
	ret += (g / 3);
	ret += (b / 3);
	r %= 3;
	g %= 3;
	b %= 3;

	if (r && g) {
		if (r == 2 || g == 2) ret += 2;
		else ret++;
	}
	else if (g && b) {
		if (g == 2 || b == 2) ret += 2;
		else ret++;
	}
	else if (b && r) {
		if (b == 2 || r == 2) ret += 2;
		else ret++;
	}
	else if (r || g || b) {
		ret++;
	}

	cout << ret << '\n';
}

void input() {
	cin >> r >> g >> b;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
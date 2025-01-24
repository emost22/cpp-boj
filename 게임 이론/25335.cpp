#include <iostream>
using namespace std;

int r, g, b;
int N, M;

void func() {
	r += (g >> 1);
	b += (g >> 1);
	if (g & 1) r++;

	if (r > b) cout << "jhnah917\n";
	else cout << "jhnan917\n";
}

void input() {
	int x, y;
	cin >> N >> M;
	while (N--) {
		cin >> x >> y;
	}

	char c;
	while (M--) {
		cin >> x >> y >> c;
		if (c == 'R') r++;
		else if (c == 'G') g++;
		else b++;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
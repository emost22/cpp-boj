#include <iostream>
#include <cmath>
#define LOG 18
using namespace std;

int x, y;

void func() {
	int p = pow(3, LOG);
	while (p) {
		if (x >= p || y >= p) break;
		p /= 3;
	}

	while (p) {
		if (x > y) x -= p;
		else y -= p;
		p /= 3;
	}

	if (!x && !y) cout << "1\n";
	else cout << "0\n";
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
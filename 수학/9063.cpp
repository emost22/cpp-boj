#include <iostream>
#include <algorithm>
using namespace std;

int N;
int minX, maxX, minY, maxY;

void func() {
	cout << (maxX - minX) * (maxY - minY) << '\n';
}

void init() {
	minX = 10000;
	maxX = -10000;
	minY = 10000;
	maxY = -10000;
}

void input() {
	int x, y;
	cin >> N;
	while (N--) {
		cin >> x >> y;
		minX = min(minX, x);
		maxX = max(maxX, x);
		minY = min(minY, y);
		maxY = max(maxY, y);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	input();
	func();

	return 0;
}
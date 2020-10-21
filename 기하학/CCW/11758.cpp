#include <iostream>
using namespace std;

int x, y, x2, y2, x3, y3;

int ccw() {
	int result = x * (y2 - y3) + x2 * (y3 - y) + x3 * (y - y2);

	if (result > 0) return 1;
	else if (!result) return 0;
	else return -1;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> x >> y >> x2 >> y2 >> x3 >> y3;
	cout << ccw() << '\n';

	return 0;
}
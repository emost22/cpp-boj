#include <iostream>
using namespace std;

typedef struct Point {
	int x, y, z;
}Point;

Point a, c;

void input() {
	cin >> a.x >> a.y >> a.z >> c.x >> c.y >> c.z;
	cout << c.x - a.z << ' ' << c.y / a.y << ' ' << c.z - a.x << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}
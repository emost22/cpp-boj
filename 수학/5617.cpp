#include <iostream>
#include <vector>
using namespace std;

typedef struct Node {
	int a, b, c;
}Node;

vector<Node> v;

bool isTriangle(Node n) {
	if (n.a <= 0 || n.b <= 0 || n.c <= 0) return false;
	return n.a < n.b + n.c;
}

int getAngle(Node n) {
	return n.a * n.a - n.b * n.b - n.c * n.c;
}

void func() {
	int ret = 0;
	int x = 0;
	int y = 0;
	int z = 0;
	for (auto n : v) {
		if (!isTriangle(n)) break;
		ret++;

		int angle = getAngle(n);
		if (angle < 0) y++;
		else if (!angle) x++;
		else z++;
	}

	cout << ret << ' ' << x << ' ' << y << ' ' << z << '\n';
}

void input() {
	int a, b, c;
	while (cin >> a) {
		cin >> b >> c;
		if (b > a && b > c) swap(a, b);
		if (c > a && c > b) swap(a, c);

		v.push_back({ a,b,c });
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
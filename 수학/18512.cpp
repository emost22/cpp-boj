#include <iostream>
using namespace std;

int X, Y, P, Q;

void func() {
	int t = 201;
	int x = P;
	int y = Q;
	while (t--) {
		if (x == y) {
			cout << x << '\n';
			return;
		}
		else if (x < y) x += X;
		else y += Y;
	}

	cout << "-1\n";
}

void input() {
	cin >> X >> Y >> P >> Q;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
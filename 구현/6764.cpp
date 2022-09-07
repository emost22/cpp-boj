#include <iostream>
using namespace std;

int a, b, c, d;

void func() {
	if (a == b && b == c && c == d) {
		cout << "Fish At Constant Depth\n";
	}
	else if (a < b && b < c && c < d) {
		cout << "Fish Rising\n";
	}
	else if (a > b && b > c && c > d) {
		cout << "Fish Diving\n";
	}
	else {
		cout << "No Fish\n";
	}
}

void input() {
	cin >> a >> b >> c >> d;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
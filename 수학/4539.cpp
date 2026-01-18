#include <iostream>
using namespace std;

int x;

void func() {
	int t = 10;
	while (x > t) {
		x = (x + (t >> 1)) / t * t;
		t *= 10;
	}

	cout << x << '\n';
}

void input() {
	cin >> x;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
	}

	return 0;
}
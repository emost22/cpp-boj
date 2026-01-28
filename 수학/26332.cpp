#include <iostream>
using namespace std;

int c, p;

void func() {
	cout << c << ' ' << p << '\n' << c * p - ((c - 1) << 1) << '\n';
}

void input() {
	cin >> c >> p;
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
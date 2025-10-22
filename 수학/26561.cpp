#include <iostream>
using namespace std;

int p, t;

void func() {
	cout << p + (t / 4 - t / 7) << '\n';
}

void input() {
	cin >> p >> t;
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
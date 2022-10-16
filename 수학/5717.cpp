#include <iostream>
using namespace std;

int x, y;

void func() {
	cout << x + y << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (1) {
		cin >> x >> y;
		if (!x) return 0;

		func();
	}
}
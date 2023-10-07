#include <iostream>
#define MAX 10
using namespace std;

int d;

void func() {
	if (!d) cout << "N\n";
	else if (d == 1)cout << "E\n";
	else if (d == 2) cout << "S\n";
	else cout << "W\n";
}

void input() {
	int x;
	for (int t = 0; t < MAX; t++) {
		cin >> x;
		d = (d + x) % 4;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
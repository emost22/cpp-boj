#include <iostream>
using namespace std;

int x, y, z;

void func() {
	if (x + y + z >= 100) cout << "OK\n";
	else {
		if (x < y && x < z) cout << "Soongsil\n";
		else if (y < z && y < x) cout << "Korea\n";
		else cout << "Hanyang\n";
	}
}

void input() {
	cin >> x >> y >> z;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
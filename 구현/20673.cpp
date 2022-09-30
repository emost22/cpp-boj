#include <iostream>
using namespace std;

int x, y;

void func() {
	if (x <= 50 && y <= 10) cout << "White\n";
	else if (y > 30) cout << "Red\n";
	else cout << "Yellow\n";
}

void input() {
	cin >> x >> y;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
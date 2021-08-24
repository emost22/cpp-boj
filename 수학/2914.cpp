#include <iostream>
using namespace std;

int x, y;

void input() {
	cin >> x >> y;
	cout << x * (y - 1) + 1 << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}
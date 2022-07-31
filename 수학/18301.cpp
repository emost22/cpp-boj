#include <iostream>
using namespace std;

void input() {
	int x, y, z;
	cin >> x >> y >> z;
	cout << (x + 1) * (y + 1) / (z + 1) - 1 << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}
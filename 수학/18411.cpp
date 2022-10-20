#include <iostream>
using namespace std;

void input() {
	int x, y, z;
	cin >> x >> y >> z;
	cout << (x < y ? x < z ? y + z : x + y : y < z ? x + z : x + y) << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}
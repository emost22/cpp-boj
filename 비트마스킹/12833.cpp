#include <iostream>
using namespace std;

void input() {
	int x, y, z;
	cin >> x >> y >> z;
	if (z % 2) x ^= y;
	cout << x << '\n';	
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}
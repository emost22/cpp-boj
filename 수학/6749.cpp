#include <iostream>
using namespace std;

void input() {
	int x, y;
	cin >> x >> y;
	cout << y + (y - x) << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}
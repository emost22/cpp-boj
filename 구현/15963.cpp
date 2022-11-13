#include <iostream>
using namespace std;

void input() {
	long long x, y;
	cin >> x >> y;

	cout << (x == y ? 1 : 0) << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}
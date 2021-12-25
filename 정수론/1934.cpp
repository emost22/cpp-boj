#include <iostream>
using namespace std;

int gcd(int x, int y) {
	return y ? gcd(y, x % y) : x;
}

void input() {
	int x, y;
	cin >> x >> y;
	cout << x * y / gcd(x, y) << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
	}

	return 0;
}
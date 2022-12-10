#include <iostream>
using namespace std;

void input() {
	int tc, x, y;
	cin >> tc;
	while (tc--) {
		cin >> x >> y;
		cout << (x * y) / 2 << '\n';
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}
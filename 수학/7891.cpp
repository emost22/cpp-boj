#include <iostream>
using namespace std;

void input() {
	int x, y;
	cin >> x >> y;
	cout << x + y << '\n';
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
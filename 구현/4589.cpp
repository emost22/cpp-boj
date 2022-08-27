#include <iostream>
using namespace std;

void input() {
	int x, y, z;
	cin >> x >> y >> z;
	if ((x < y && y < z) || (x > y && y > z)) cout << "Ordered\n";
	else cout << "Unordered\n";
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	cout << "Gnomes:\n";
	while (tc--) {
		input();
	}

	return 0;
}
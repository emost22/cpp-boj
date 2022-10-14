#include <iostream>
using namespace std;

void input() {
	int N, x, y;
	cin >> N;
	while (N--) {
		cin >> x >> y;
		cout << x + y << ' ' << x * y << '\n';
	}
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
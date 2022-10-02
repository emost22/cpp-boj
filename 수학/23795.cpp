#include <iostream>
using namespace std;

void input() {
	int x;
	int ans = 0;
	while (1) {
		cin >> x;
		if (x == -1) {
			cout << ans << '\n';
			return;
		}

		ans += x;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}
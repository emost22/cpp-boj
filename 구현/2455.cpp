#include <iostream>
#include <algorithm>
using namespace std;

void input() {
	int x, y;
	int sum = 0;
	int ans = 0;
	for (int i = 0; i < 4; i++) {
		cin >> x >> y;
		sum += (y - x);
		ans = max(ans, sum);
	}

	cout << ans << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}
#include <iostream>
using namespace std;

void input() {
	int ans = 0;
	int x;
	for (int i = 0; i < 5; i++) {
		cin >> x;
		ans += x;
	}

	cout << ans << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}
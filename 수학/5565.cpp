#include <iostream>
using namespace std;

int ans;

void input() {
	int x;
	cin >> ans;
	for (int i = 0; i < 9; i++) {
		cin >> x;
		ans -= x;
	}

	cout << ans << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}
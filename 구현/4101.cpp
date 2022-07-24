#include <iostream>
using namespace std;

void input() {
	int x, y;
	while (1) {
		cin >> x >> y;
		if (!x) return;

		cout << (x > y ? "Yes\n" : "No\n");
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}
#include <iostream>
using namespace std;

void input() {
	int x, y;
	cin >> x >> y;
	int ans = x * 8 + y * 3 - 28;
	cout << (ans > 0 ? ans : 0) << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}
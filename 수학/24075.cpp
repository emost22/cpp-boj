#include <iostream>
#include <algorithm>
using namespace std;

void input() {
	int x, y;
	cin >> x >> y;
	cout << max(x + y, x - y) << '\n' << min(x + y, x - y) << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}
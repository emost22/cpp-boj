#include <iostream>
#include <algorithm>
using namespace std;

void input() {
	int a, b, c, d, x, y, z, w;
	cin >> a >> b >> c >> d >> x >> y >> z >> w;
	cout << max(a + b + c + d, x + y + z + w) << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}
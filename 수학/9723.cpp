#include <iostream>
using namespace std;

int a, b, c;

void func(int tc) {
	if (a > b && a > c) swap(a, c);
	else if (b > a && b > c) swap(b, c);

	if (a * a + b * b == c * c) cout << "Case #" << tc << ": YES\n";
	else cout << "Case #" << tc << ": NO\n";
}

void input() {
	cin >> a >> b >> c;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		input();
		func(t);
	}

	return 0;
}
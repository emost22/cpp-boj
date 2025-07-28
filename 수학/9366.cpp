#include <iostream>
using namespace std;

int a, b, c;

void func(int tc) {
	if (b >= a && b >= c) swap(a, b);
	else if (c >= a && c >= b) swap(a, c);

	if (a == b && b == c) cout << "Case #" << tc << ": equilateral\n";
	else if (a >= b + c) cout << "Case #" << tc << ": invalid!\n";
	else if (a == b || b == c || a == c) cout << "Case #" << tc << ": isosceles\n";
	else cout << "Case #" << tc << ": scalene\n";
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
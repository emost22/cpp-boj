#include <iostream>
using namespace std;

double x, y;

void func() {
	if (x > 0.0 && y > 0.0) cout << "Q1\n";
	else if (x < 0.0 && y > 0.0) cout << "Q2\n";
	else if (x < 0.0 && y < 0.0) cout << "Q3\n";
	else if (x > 0.0 && y < 0.0) cout << "Q4\n";
	else cout << "AXIS\n";

	if (x == 0.0 && y == 0.0) exit(0);
}

void input() {
	cin >> x >> y;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (1) {
		input();
		func();
	}

	return 0;
}
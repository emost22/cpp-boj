#include <iostream>
using namespace std;

double d, f, p;

void func() {
	cout << fixed; cout.precision(2);
	cout << '$' << d * f * p << '\n';
}

void input() {
	cin >> d >> f >> p;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
	}

	return 0;
}
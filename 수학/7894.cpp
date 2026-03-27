#include <iostream>
#include <cmath>
using namespace std;

double m;

void func() {
	double ret = 0;
	for (double i = 2; i <= m; i++) {
		ret += log10(i);
	}

	cout << (int)ret + 1 << '\n';
}

void input() {
	cin >> m;
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
#include <iostream>
#define MAX 5
using namespace std;

double price[MAX] = { 350.34, 230.90, 190.55, 125.30, 180.90 };
double a, b, c, d, e;

void func() {
	cout << fixed;
	cout.precision(2);
	cout << "$" << a * price[0] + b * price[1] + c * price[2] + d * price[3] + e * price[4] << '\n';
}

void input() {
	cin >> a >> b >> c >> d >> e;
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
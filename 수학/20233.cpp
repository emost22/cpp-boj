#include <iostream>
#include <algorithm>
#define FREEA 30
#define FREEB 45
#define NOV 21
using namespace std;

int a, x, b, y, t;

void func() {
	int ax = max(0, t - FREEA) * x * NOV + a;
	int by = max(0, t - FREEB) * y * NOV + b;
	cout << ax << ' ' << by << '\n';
}

void input() {
	cin >> a >> x >> b >> y >> t;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
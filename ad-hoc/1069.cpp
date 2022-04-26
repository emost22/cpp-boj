#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

double x, y, d, t;

void func() {
	double dis = sqrt(x * x + y * y);
	double ans = dis;
	int cnt = dis / d;
	dis -= (cnt * d);

	if (!cnt) {
		ans = min(ans, min(t + d - dis, t * 2.0));
	}
	else {
		ans = min(ans, min((double)cnt * t + dis, (double)(cnt + 1) * t));
	}

	cout << fixed; cout.precision(9);
	cout << ans << '\n';
}

void input() {
	cin >> x >> y >> d >> t;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
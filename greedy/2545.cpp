#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll a[3], d;

void func() {
	sort(a, a + 3);
	ll tmp = a[0] + a[1] + a[2] - d;
	a[0] = min(a[0], tmp / 3LL);
	a[1] = min(a[1], (tmp - a[0]) >> 1);
	a[2] = tmp - a[0] - a[1];
	cout << a[0] * a[1] * a[2] << '\n';
}

void input() {
	cin >> a[0] >> a[1] >> a[2] >> d;
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
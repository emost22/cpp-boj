#include <iostream>
using namespace std;
typedef long long ll;

ll x, y, r, x2, y2, r2;

void func() {
	ll d = (x2 - x) * (x2 - x) + (y2 - y) * (y2 - y);
	ll sr = (r + r2) * (r + r2);

	if (d < sr) cout << "YES\n";
	else cout << "NO\n";
}

void input() {
	cin >> x >> y >> r >> x2 >> y2 >> r2;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
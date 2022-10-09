#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll N, M, f, c, sx, sy, ex, ey;

void func() {
	ll fx = f;
	if (f > N / 2) fx = N - f;

	ll ans = N * M;
	if (fx <= sx) {
		ans -= ((c + 1) * (ex - sx) * (ey - sy));
	}
	else if (fx >= ex) {
		ans -= (2 * (c + 1) * (ex - sx) * (ey - sy));
	}
	else {
		ans -= (2 * (c + 1) * (fx - sx) * (ey - sy) + (c + 1) * (ex - fx) * (ey - sy));
	}

	cout << ans << '\n';
}

void input() {
	cin >> N >> M >> f >> c >> sx >> sy >> ex >> ey;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
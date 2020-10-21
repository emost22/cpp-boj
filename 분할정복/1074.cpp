#include <iostream>
using namespace std;

int ans, a = 1, N, r, c;

void div(int size, int sx, int sy, int ex, int ey) {
	if (size == 2) {
		if (r == sx && c == sy) ans++;
		else if (r == sx && c == ey) ans += 2;
		else if (r == ex && c == sy) ans += 3;
		else if (r == ex && c == ey) ans += 4;

		return;
	}
	
	if (r <= (sx + ex) / 2 && c <= (sy + ey) / 2) {
		div(size / 2, sx, sy, (sx + ex) / 2, (sy + ey) / 2);
	}
	else if (r <= (sx + ex) / 2 && c > (sy + ey) / 2) {
		ans += (size / 2)*(size / 2);
		div(size / 2, sx, (sy + ey) / 2 + 1, (sx + ex) / 2, ey);
	}
	else if (r > (sx + ex) / 2 && c <= (sy + ey) / 2) {
		ans += (size / 2)*(size / 2) * 2;
		div(size / 2, (sx + ex) / 2 + 1, sy, ex, (sy + ey) / 2);
	}
	else {
		ans += (size / 2)*(size / 2) * 3;
		div(size / 2, (sx + ex) / 2 + 1, (sy + ey) / 2 + 1, ex, ey);
	}
}

void mul() {
	for (int i = 0; i < N; i++) {
		a *= 2;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> r >> c;

	mul();
	div(a, 0, 0, a - 1, a - 1);
	cout << ans - 1 << '\n';

	return 0;
}
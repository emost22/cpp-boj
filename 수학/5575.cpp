#include <iostream>
using namespace std;

typedef struct Time {
	int h, m, s;
}Time;

Time a, b;

void func() {
	Time ans = { b.h - a.h, b.m - a.m, b.s - a.s };
	if (ans.m < 0) {
		ans.h--;
		ans.m += 60;
	}

	if (ans.s < 0) {
		ans.m--;
		if (ans.m < 0) {
			ans.h--;
			ans.m += 60;
		}
		ans.s += 60;
	}

	cout << ans.h << ' ' << ans.m << ' ' << ans.s << '\n';
}

void input() {
	cin >> a.h >> a.m >> a.s >> b.h >> b.m >> b.s;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	for (int t = 0; t < 3; t++) {
		input();
		func();
	}

	return 0;
}
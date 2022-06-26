#include <iostream>
#include <algorithm>
#define MAX 100000000
using namespace std;

int M;

void func() {
	int l = 1;
	int r = MAX * 5;
	int ans = -1;
	while (l <= r) {
		int m = (l + r) / 2;

		int cnt = 0;
		for (int i = 5; i <= m; i *= 5) {
			cnt += (m / i);
		}

		if (cnt >= M) {
			if (cnt == M) {
				ans = m;
			}
			r = m - 1;
		}
		else {
			l = m + 1;
		}
	}

	cout << ans << '\n';
}

void input() {
	cin >> M;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
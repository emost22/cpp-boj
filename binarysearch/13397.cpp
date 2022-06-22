#include <iostream>
#include <algorithm>
#define MAX 5001
using namespace std;

int list[MAX];
int N, M, l, r;

void func() {
	int ans = 0;
	while (l <= r) {
		int m = (l + r) / 2;

		int minValue = 10000;
		int maxValue = 1;
		int cnt = 1;
		for (int i = 0; i < N; i++) {
			minValue = min(minValue, list[i]);
			maxValue = max(maxValue, list[i]);

			if (maxValue - minValue > m) {
				cnt++;
				maxValue = minValue = list[i];
			}
		}

		if (cnt <= M) {
			ans = m;
			r = m - 1;
		}
		else {
			l = m + 1;
		}
	}

	cout << ans << '\n';
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
		r = max(r, list[i]);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
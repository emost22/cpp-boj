#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> list;
int N, K, M, l, r;

void func() {
	int ans = -1;
	l = 1;
	while (l <= r) {
		int m = (l + r) >> 1;

		int cnt = 0;
		for (int i = 0; i < N; i++) {
			if (list[i] <= K) continue;

			if (list[i] >= K * 2) cnt += ((list[i] - K * 2) / m);
			else cnt += ((list[i] - K) / m);
		}

		if (cnt >= M) {
			ans = m;
			l = m + 1;
		}
		else {
			r = m - 1;
		}
	}

	cout << ans << '\n';
}

void input() {
	int x;
	cin >> N >> K >> M;
	for (int i = 0; i < N; i++) {
		cin >> x;

		list.push_back(x);
		r = max(r, x);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
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
			cnt += (list[i] / m);
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
		if (x <= K || x == K * 2) continue;

		int sub = x;
		if (x < K * 2) sub -= K;
		else sub -= (K * 2);

		list.push_back(sub);
		r = max(r, sub);
	}

	N = list.size();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
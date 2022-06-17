#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;

int list[MAX];
int N, M, maxCash, sum;

bool chk(int m) {
	if (m < maxCash) return false;

	int cnt = 1;
	int cash = m;
	for (int i = 0; i < N; i++) {
		if (cash < list[i]) {
			cash = m;
			cnt++;
		}

		cash -= list[i];
	}

	return cnt <= M;
}

void func() {
	int l = 0;
	int r = sum;
	int ans = 0;
	while (l <= r) {
		int m = (l + r) / 2;

		if (chk(m)) {
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
		maxCash = max(maxCash, list[i]);
		sum += list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
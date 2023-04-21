#include <iostream>
#include <algorithm>
#define MAX_N 100001
#define MAX_L 200000
using namespace std;

int list[MAX_N];
int L, N, K, maxDis;

void func() {
	int l = maxDis;
	int r = MAX_L;

	int ret = 0;
	while (l <= r) {
		int m = (l + r) / 2;

		int now = m;
		int pos = 0;
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			if (list[i] - pos > now) {
				cnt++;
				now = m;
			}
			now -= (list[i] - pos);
			pos = list[i];
		}

		if (cnt <= K) {
			ret = m;
			r = m - 1;
		}
		else {
			l = m + 1;
		}
	}

	cout << ret << '\n';
}

void input() {
	cin >> L >> N >> K;

	int pre = 0;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
		maxDis = max(maxDis, list[i] - pre);
		pre = list[i];
	}
	maxDis = max(maxDis, L - pre);
	list[N++] = L;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
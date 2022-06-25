#include <iostream>
#include <algorithm>
#define MAX 50003
using namespace std;

int list[MAX];
int d, N, M;

void func() {
	int l = 1;
	int r = d;
	int ans = 0;
	while (l <= r) {
		int m = (l + r) / 2;

		int cnt = 0;
		int pre = list[0];
		for (int i = 1; i < N; i++) {
			int dis = list[i] - pre;

			if (dis < m) {
				cnt++;
			}
			else {
				pre = list[i];
			}
		}

		if (cnt <= M) {
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
	cin >> d >> N >> M;
	list[0] = 0;
	list[1] = d;
	N += 2;
	for (int i = 2; i < N; i++) {
		cin >> list[i];
	}
	sort(list, list + N);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
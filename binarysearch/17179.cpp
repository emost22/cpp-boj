#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;

int list[MAX];
int N, M, K;

bool chk(int m, int cnt) {
	int pre = 0;
	for (int i = 0; i <= M; i++) {
		int len = list[i] - pre;

		if (len >= m) {
			pre = list[i];
			cnt--;
		}
	}

	return cnt < 0 ? true : false;
}

void func() {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		cin >> cnt;
		
		int l = 0;
		int r = K;
		int ans = 0;
		while (l <= r) {
			int m = (l + r) / 2;
			if (chk(m, cnt)) {
				l = m + 1;
				ans = max(ans, m);
			}
			else r = m - 1;
		}

		cout << ans << '\n';
	}
}

void input() {
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		cin >> list[i];
	}
	list[M] = K;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
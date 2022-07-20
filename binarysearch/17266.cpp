#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;

int list[MAX];
int N, M;

void func() {
	int l = 1;
	int r = N;
	int ans = 0;
	while (l <= r) {
		int m = (l + r) / 2;

		int now = 0;
		bool flag = true;
		for (int i = 0; i < M; i++) {
			if (now >= list[i] - m) {
				now = list[i] + m;
				if (now >= N) break;
			}
			else {
				flag = false;
				break;
			}
		}

		if (flag && now >= N) {
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
	for (int i = 0; i < M; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;

int list[501];
int N, M, maxheight, idx;

void func() {
	int ans = 0;
	int nowmax = 0;
	for (int i = 1; i <= idx; i++) {
		nowmax = max(nowmax, list[i]);

		if (nowmax > list[i]) {
			ans += (nowmax - list[i]);
		}
	}

	nowmax = 0;
	for (int i = N; i > idx; i--) {
		nowmax = max(nowmax, list[i]);

		if (nowmax > list[i]) {
			ans += (nowmax - list[i]);
		}
	}

	cout << ans << '\n';
}

void input() {
	cin >> M >> N;
	for (int i = 1; i <= N; i++) {
		cin >> list[i];
		if (maxheight < list[i]) {
			maxheight = list[i];
			idx = i;
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
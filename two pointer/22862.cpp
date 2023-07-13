#include <iostream>
#include <algorithm>
#define MAX 1000001
using namespace std;

int list[MAX];
int N, K;

void func() {
	int cnt = 0;
	int l = 1;
	int r = l;
	for (; r <= N; r++) {
		if (list[r] % 2) {
			cnt++;
			if (cnt == K) break;
		}
	}
	if (r > N) r--;

	int ret = r - l + 1 - cnt;
	while (r < N) {
		if (list[r + 1] % 2) {
			while (l < r && !(list[l] % 2)) {
				l++;
			}
			l++;
		}
		r++;
		ret = max(ret, r - l + 1 - cnt);
	}

	cout << ret << '\n';
}

void input() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
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
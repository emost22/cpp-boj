#include <iostream>
#define MAX 1000001
using namespace std;

int list[MAX];
int N, M;

void func() {
	int x;
	int ans = 0;
	while (M--) {
		cin >> x;
		int l = 0;
		int r = N - 1;
		while (l <= r) {
			int m = (l + r) / 2;

			if (list[m] == x) {
				ans++;
				break;
			}
			else if (list[m] > x) {
				r = m - 1;
			}
			else {
				l = m + 1;
			}
		}
	}

	cout << ans << '\n';
}

void input() {
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (1) {
		cin >> N >> M;
		if (!N) return 0;
		input();
		func();
	}
}
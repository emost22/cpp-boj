#include <iostream>
#include <algorithm>
#define MAX 1000000
using namespace std;

int list[MAX];
int N, K;

void func() {
	int l = 0;
	int r = 0;
	int ans = 1e9;
	int cnt = 0;
	while (r < N) {
		if (list[r] == 1) cnt++;

		while (cnt >= K) {
			ans = min(ans, r - l + 1);

			if (list[l] == 1) cnt--;
			l++;
		}

		r++;
	}

	if (ans == 1e9) cout << "-1\n";
	else cout << ans << '\n';
}

void input() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
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
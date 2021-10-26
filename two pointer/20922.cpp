#include <iostream>
#include <algorithm>
#define MAX 200000
using namespace std;

int list[MAX], cnt[MAX / 2 + 1];
int N, K;

void func() {
	int l = 0;
	int r = 0;
	int ans = 0;
	while (r < N) {
		cnt[list[r]]++;
		while (cnt[list[r]] > K) {
			cnt[list[l]]--;
			l++;
		}
		r++;

		ans = max(ans, r - l);
	}

	cout << ans << '\n';
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
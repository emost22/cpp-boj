#include <iostream>
#include <algorithm>
using namespace std;

int list[3003001], pick[3001];
int N, d, k, c, ans;

void func() {
	int l = 0;
	int r = k - 1;
	pick[c] = 1;
	ans++;
	for (int i = l; i <= r; i++) {
		if (pick[list[i]]++ == 0) ans++;
	}

	int cnt = ans;
	while (1) {
		l++;
		if (l == N) break;
		r = (r + 1) % N;

		if (--pick[list[l - 1]] == 0) cnt--;
		if (pick[list[r]]++ == 0) cnt++;

		ans = max(ans, cnt);
	}

	cout << ans << '\n';
}

void input() {
	cin >> N >> d >> k >> c;
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
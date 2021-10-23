#include <iostream>
#include <algorithm>
#define MAX 3001
using namespace std;

int list[MAX * 10], pick[MAX];
int N, d, k, c;

void func() {
	int l = 0;
	int r = k - 1;
	int ans = 1;
	pick[c]++;
	for (int i = l; i <= r; i++) {
		if (!pick[list[i]]) ans++;
		pick[list[i]]++;
	}

	int cnt = ans;
	while (l < N) {
		r = (r + 1) % N;
		l++;

		pick[list[l - 1]]--;
		if (!pick[list[l - 1]]) cnt--;
		if (!pick[list[r]]) cnt++;
		pick[list[r]]++;

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
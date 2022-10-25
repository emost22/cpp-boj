#include <iostream>
using namespace std;

int N, M;

void func() {
	int ans = 0;
	for (int i = N; i <= M; i++) {
		if (!i) {
			ans++;
			continue;
		}

		int tmp = i;
		while (tmp) {
			ans += !(tmp % 10);
			tmp /= 10;
		}
	}

	cout << ans << '\n';
}

void input() {
	cin >> N >> M;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
	}

	return 0;
}
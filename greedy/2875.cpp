#include <iostream>
using namespace std;

int N, M, K, ans, cnt;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M >> K;

	if (N / 2 > M) {
		ans = M;
		cnt = N - (M * 2);
	}
	else if (M > N / 2) {
		ans = N / 2;
		cnt = M - ans;
	}
	else {
		ans = M;
		cnt = 0;
	}

	if (K >= cnt) {
		K -= cnt;
		cnt = 0;

		if (K % 3 == 0) ans -= (K / 3);
		else ans -= (K / 3 + 1);
	}
	cout << ans << '\n';

	return 0;
}
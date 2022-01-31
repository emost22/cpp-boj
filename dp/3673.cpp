#include <iostream>
#include <cstring>
#define MAX_N 50001
#define MAX_M 1000000
using namespace std;
typedef long long ll;

ll dp[MAX_N], cnt[MAX_M];
int N, M;

void func() {
	ll ans = cnt[0];
	for (int i = 0; i < M; i++) {
		if (cnt[i] < 2) continue;
		ans += ((cnt[i] * (cnt[i] - 1)) / 2LL);
	}

	cout << ans << '\n';
}

void input() {
	cin >> M >> N;
	for (int i = 1; i <= N; i++) {
		cin >> dp[i];
		dp[i] += dp[i - 1];

		cnt[dp[i] % M]++;
	}
}

void init() {
	memset(cnt, 0, sizeof(cnt));
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
		init();
	}

	return 0;
}
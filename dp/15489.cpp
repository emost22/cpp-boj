#include <iostream>
#define MAX 31
using namespace std;
typedef long long ll;

ll dp[MAX][MAX];
int N, M, len;

void func() {
	ll ans = 0;
	for (int i = N; i < N + len; i++) {
		for (int j = M; j <= M + i - N; j++) {
			ans += dp[i][j];
		}
	}

	cout << ans << '\n';
}

void init() {
	for (int i = 1; i < MAX; i++) {
		dp[i][1] = 1;
	}

	for (int i = 2; i < MAX; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
		}
	}
}

void input() {
	cin >> N >> M >> len;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	input();
	func();

	return 0;
}
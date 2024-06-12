#include <iostream>
#include <algorithm>
#define MAX_N 21
#define MAX_M 211
using namespace std;
typedef long long ll;

ll dp[MAX_N][MAX_M];
int N, M;

void init() {
	dp[1][0] = 1LL;
	dp[1][1] = 1LL;
	for (int i = 2; i < MAX_N; i++) {
		for (int j = 0; j <= (i * (i + 1)) >> 1; j++) {
			for (int k = max(0, j - i); k <= j; k++) {
				dp[i][j] += dp[i - 1][k];
			}
		}
	}
}

void func() {
	cout << dp[N][M] << '\n';
}

void input() {
	cin >> N >> M;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
	}

	return 0;
}
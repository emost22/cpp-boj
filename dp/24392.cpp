#include <iostream>
#include <algorithm>
#define MAX 1001
#define MOD 1000000007
using namespace std;

int list[MAX][MAX], dp[MAX][MAX];
int N, M;

void func() {
	for (int i = 0; i < M; i++) {
		dp[0][i] = list[0][i];
	}

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!list[i][j]) continue;
			dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
			if (j) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
			if (j < M - 1) dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
		}
	}

	int ans = 0;
	for (int i = 0; i < M; i++) {
		ans = (ans + dp[N - 1][i]) % MOD;
	}

	cout << ans << '\n';
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> list[i][j];
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
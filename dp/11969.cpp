#include <iostream>
#define MAX 100001
using namespace std;

int dp[MAX][4];
int N, M;

void func() {
	for (int i = 1; i <= N; i++) {
		dp[i][1] += dp[i - 1][1];
		dp[i][2] += dp[i - 1][2];
		dp[i][3] += dp[i - 1][3];
	}

	int l, r;
	while (M--) {
		cin >> l >> r;
		cout << dp[r][1] - dp[l - 1][1] << ' ' << dp[r][2] - dp[l - 1][2] << ' ' << dp[r][3] - dp[l - 1][3] << '\n';
	}
}

void input() {
	int x;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> x;
		dp[i][x]++;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
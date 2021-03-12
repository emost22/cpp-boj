#include <iostream>
using namespace std;

int list[2001], dp[2001][2001];
int N, M;

void solve() {
	int x, y;
	while (M--) {
		cin >> x >> y;
		cout << dp[x][y] << '\n';
	}
}

void func() {
	for (int i = 2; i < N; i++) {
		for (int j = 1; j <= N - i; j++) {
			if (dp[j + 1][j + i - 1] && (list[j] == list[j + i])) {
				dp[j][j + i] = 1;
			}
		}
	}
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> list[i];
		dp[i][i] = 1;
		if (list[i - 1] == list[i]) dp[i - 1][i] = 1;
	}
	cin >> M;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();
	solve();

	return 0;
}
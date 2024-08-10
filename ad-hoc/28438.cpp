#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > dp;
int N, M, Q;

void func() {
	int type, x, y;
	while (Q--) {
		cin >> type >> x >> y;
		if (type == 1) {
			dp[x][1] += y;
			dp[x + 1][1] -= y;
		}
		else {
			dp[1][x] += y;
			dp[1][x + 1] -= y;
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			dp[i][j] = dp[i][j] + dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cout << dp[i][j] << ' ';
		}
		cout << '\n';
	}
}

void input() {
	cin >> N >> M >> Q;
	dp.resize(N + 2, vector<int>(M + 2, 0));
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}
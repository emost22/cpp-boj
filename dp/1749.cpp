#include <iostream>
#include <algorithm>
#define MAX 201
using namespace std;

int dp[MAX][MAX];
int N, M;

void func() {
	int ret = -10001;
	for (int sx = 1; sx <= N; sx++) {
		for (int sy = 1; sy <= N; sy++) {
			for (int ex = sx; ex <= N; ex++) {
				for (int ey = sy; ey <= N; ey++) {
					ret = max(ret, dp[ex][ey] - dp[ex][sy - 1] - dp[sx - 1][ey] + dp[sx - 1][sy - 1]);
				}
			}
		}
	}

	cout << ret << '\n';
}

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> dp[i][j];
			dp[i][j] += (dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1]);
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
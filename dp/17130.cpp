#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 1010
using namespace std;

char list[MAX][MAX];
int dp[MAX][MAX];
int direct[3] = { -1,0,1 };
int N, M, sx, sy;

void func() {
	memset(dp, -1, sizeof(dp));
	dp[sx][sy] = 0;
	int ret = 0;
	bool flag = false;
	for (int j = sy + 1; j <= M; j++) {
		for (int i = 1; i <= N; i++) {
			if (list[i][j] == '#') continue;
			for (int d = 0; d < 3; d++) {
				int nx = i + direct[d];
				int ny = j - 1;
				if (nx < 1 || ny < 1 || nx > N) continue;
				if (dp[nx][ny] == -1) continue;
				if (dp[i][j] == -1) dp[i][j] = 0;
				dp[i][j] = max(dp[i][j], dp[nx][ny]);
			}

			if (list[i][j] == 'C' && dp[i][j] != -1) dp[i][j]++;
			else if (list[i][j] == 'O' && dp[i][j] != -1) {
				flag = true;
				ret = max(ret, dp[i][j]);
			}
		}
	}

	if (!ret && !flag) ret = -1;
	cout << ret << '\n';
}

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> list[i][j];
			if (list[i][j] == 'R') {
				sx = i;
				sy = j;
			}
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